# Nome do trabalho - 2017/01
# Matheus Nogueira	<matheus.nogueira2008@gmail.com>
#
#

cmake_minimum_required (VERSION 2.6)

#### Opções que podem ser ativadas pelo usuário em tempo de compilação ####
# Para ativar os testes de unidade
# -Dtest=ON
# Padrão: Desativado
option(test "Building unit tests." OFF)

# Para definir modo de debug
# -Ddebug=OFF
# Padrão: Desativado
option(debug "Buiding in debug mode" OFF)

# Define se o GNU G++ será utilizado para compilar o código
# -Dgnucompiler=ON
# Padrão: Ativado
option(gnucompiler "Building using GNU G++" ON)

#### Configurações básicas do projeto ####
# Nome do projeto
set (PROJECT_NAME heuristics)

# Tipo de build que será realizada
# Por padrão, o programa é compilado para modo release, porém, caso -Ddebug=ON é especificado,
# o modo de construção do programa é alterado para Debug
set(PROJECT_BUILD_TYPE Debug)

# Bibliotecas que o programa utiliza como dependência
# set (PROJECT_EXTERNAL_LIBS )

#### Condições de configuração ####
# Área que usa as opções do usuário para construir o programa corretamente.
# Compilador que será utilizado
if (gnucompiler)
	SET (CMAKE_CXX_COMPILER				"/usr/bin/g++")
	SET (CMAKE_COMPILER_IS_GNUCXX ON)
else()
	SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
	MESSAGE(WARNING "TEST COVERAGE NOT SUPPORTED BY CLANG, DESABLING IT")
endif()

# Ativa o modo de debug para a construção do programa
if (debug)
	MESSAGE (WARNING "DEBUG MODE ENABLED.")
	# Muda o tipo de build do programa
	set (PROJECT_BUILD_TYPE Debug)
	# Ativa a cobertura de testes
	# Ainda será incorporado ao build system
	# TODO: Consertar falha com CMP0037 no target do cmake
	# set (COVERAGE_TEST ON)
	# Define as flags de debug do compilador
	set (CMAKE_CXX_FLAGS "-g -O0 -Wall")
endif()

# Ativa a construção dos testes de unidade do programa
if (test)
	# define a pasta do gtest
    set (GTEST_DIR libs/gtest)
	# Procura todos os arquivos de teste do programa
    file (GLOB_RECURSE TESTS tests/*.cpp)
	# Faz a mágica:
	# Pega todos os testes de unidade, compila todos os arquivos e os linka
	# com a biblioteca que será criada com o código fonte do programa.
    ADD_SUBDIRECTORY(${GTEST_DIR})
    enable_testing()
    include_directories(${GTEST_DIR}/include ${GTEST_DIR})
    add_executable(tests ${TESTS})
    TARGET_LINK_LIBRARIES (tests gtest gtest_main tsp_lib)
endif()


# Configuração do projeto em si
# Nessa área, o cmake irá utilizar todas as configurações utilizadas previamente para
# montar o makefile
#
# ============================ VOCÊ NÃO PRECISA ALTERAR DAQUI PARA BAIXO ==========================
#

# Define o nome do projeto
project (${PROJECT_NAME})

# Define o tipo de build
set(CMAKE_BUILD_TYPE ${PROJECT_BUILD_TYPE})

# Inclui a pasta "include" como local para se procurar arquivos de cabeçalho
# do programa.
include_directories(include)

# Procura todos os arquivos com extensão cpp para ser compilados e gerar
# os arquivos objeto.
file (GLOB_RECURSE SOURCES src/tsp/*.cpp)

# Cria uma biblioteca para ser linkada ao programa real, dessa forma, fica mais
# simples de executar os testes de unidade, se eles existirem.
add_library(tsp_lib ${SOURCES})

# Cria um executável para o projeto
# Esse executável só será o arquivo main, pois o restante do programa já foi
# compilado previamente, e foi gerado uma biblioteca com suas funções.
add_executable (${PROJECT_NAME} src/main.cpp)

# Linka o programa main com a biblioteca previamente gerada com o restante dos
# arquivos fonte.
TARGET_LINK_LIBRARIES (${PROJECT_NAME} ${PROJECT_EXTERNAL_LIBS} tsp_lib)

##### DEFINIÇÂO DAS VARIAVEIS DO CMAKE #####
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)