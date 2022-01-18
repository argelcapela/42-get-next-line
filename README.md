<!--<div id="portfolio-slideshow-items" class="hide-on-portfolio" visibility="0">
    
</div>
-->

<div class="hide-on-portfolio">
<div align="center">
	<img src="https://github.com/argelcapela/argelcapela.rf.gd/blob/main/assets/img/galeria/portfolio_img_42-get-next-line.jpg?raw=true" width="250px">
</div>
	
# :sparkles: O que é a Get Next Line ?
O Objetivo é criar uma função em C, dentro de algumas restrições, que leia uma linha de um Descritor de Arquivo ( é mais fácil entender na prática), em outras palavras , de um arquivo de texto. Cada vez que essa função get_next_line() é chamada, deve retornar a linha seguinte, até o final do arquivo. Excelente para praticar lógica, ponteiros e leaks(vazamentos) de memória. MUUITOS LEAKS DE MEMÓRIA.
</div>

<div class="col-12">

# :wrench: Tecnologias utilizadas:<br>
<div style="display: inline_block">
    <img align="center" alt="gel-Js" height="30" width="40" src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg">

</div>

<div class="col-12">

# :rocket: Rodando o projeto:<br>
<b>Links:</b>
<li>Repositório Github: <a href="https://github.com/argelcapela/42_get_next_line">Link</a></li>
<li>Intra 42SP: <a href="https://projects.intra.42.fr/42cursus-get_next_line">Link</a></li>
<br><br>
<b> Depois de clonar o repositório, dentro da pasta test, pode-se executar esses comandos e testar rapidamente o projeto:</b><br><br>
	
```
make lin
```
<p>Compila e executa no ambiente linux</p>

```
make lincat
```
<p>Compila e executa no ambiente linux com o cat -e no retorno (quebras de linha serão exibidas com $)</p>
	
```
make win
```
<p>Compila e executa no ambiente windows</p>
	
```
make leak
```
<p>Compila e executa o valgrind, ambiente linux, com todas as principais flags para buscar leaks de memória!</p>
	
```
make tester
```
<p>Executa o tester Tripoulle!</p>
		
	
</div>
<br>
<div class="col-12">
    
# :pushpin: O que eu aprendi e como foi desenvolvido esse projeto?<br>
<b>1) Fazendo a GNL ler linha por linha</b><br>
<li><a href="#algoritmo">Lógica GNL</a></li>
<li><a href="#static-variable">Variáveis Estáticas</a></li>
<li><a href="#arrpon">Arrays e Ponteiros</a></li>
<li><a href="#stack-heap">Divisões da Memória</a></li>
<li><a href="#open-read-fd">Open, File Descriptor, Read</a></li>
<li><a href="#runtime-macro">Definir Macro em Tempo de Compilação</a></li>
<li><a href="#debug">Como usar o Debugger (GDB/VSCODE)</a></li>
<br>
	
<b>2) Leaks e Testers</b>
<li><a href="#leaks">Erros de Memória</a></li>
<li><a href="#test">Testes automatizados</a></li>
<br>
	
<b>3) Extra</b>
<li><a href="#step-by-step"> 42-get-next-line Passo a Passo!</a></li>
<li><a href="#fontes">Fontes</a></li>
</div>
<br>	
	
<div class="col-12">
	
# :handshake: Colaboradores:<br>
<table>
  <tr>
    <td align="center">
      <a href="http://github.com/argelcapela">
        <img src="https://avatars.githubusercontent.com/u/79276276?s=400&u=055b803f4708d59eaf50208ba601f85844125757&v=4" width="100px;" alt="Foto de Argel Capela!"/><br>
        <sub>
          <b>Argel Capela</b>
        </sub>
      </a>
    </td>
  </tr>
</table>
</div>
<div class="col-12">
    
# :dart: Status do projeto:<br>
<img src="https://github.com/argelcapela/argelcapela.rf.gd/blob/main/assets/icons/finalizado.png?raw=true" width="300px" height="230px">
</div>

<br><br><br>
<br><br><br>
<br><br>
	
<div align="center">

# :crown: 
	
</div>    
<br><br>
	
<h2 id="algoritmo">Algoritmo GNL?</h2>
<img src="" alt="Algoritmo GNL!"> 
<br><br>
	
<h2 id="static-variable">Variáveis Estáticas</h2>
<b>O que são Variáveis Estáticas ,pelo amor do pai ?</b>
<p>Uma variável que você coloca um valor nela, e esse valor, fica ali, não importa o que aconteça, <u>até o programa acabar, ou até você atribuir outro valor aquela variável.</u></p>
<br>
    
<b>Coisas relevantes que eu deva saber dessa jóssa?</b>
<ul>
    <li>Ela começa valendo 0, mesmo sem nada ser atribuído.</li>
    <li>A variável estática é inicializada somente uma vez durante o programa, não importa se uma função passa várias vezes pela linha que declara a variável estática, depois da primeira vez que essa linha é executada, nas outras vezes ela será "ignorada".</li>
</ul>
<br>
    
<b>Bora, ver algumas diferenças entre V. Estáticas e Locais? Rapidão...</b>
<table>
<thread>
    <tr>
        <td>Pontos Diferentes</td>
        <td>Variável Local</td>
        <td>Variável Estática</td>
    </tr>
</thead>
<tbody>    
    <tr>
        <td>Quando declarada sem atribuir nenhum valor, qual o valor padrão?</td>
        <td>Um valor lixo da memória</td>
        <td>0</td>
    </tr>
    <tr>
        <td>Onde é criada?</td>
        <td>Dentro de uma função</td>
        <td>Dentro de uma função, ou fora, tanto faz.</td>
    </tr>
    <tr>
        <td>Quando essa variável é destruída?</td>
        <td>Quando a função termina a sua execução.</td>
        <td>Quando o programa, para de rodar.</td>
    </tr>
    <tr>
        <td>É armazenada em que parte da memória?</td>
        <td>Stack</td>
	    <td>
		    <li>BSS: estáticas não inicializadas</li>
		    <li>DATA: estáticas inicializadas</li>
	    </td>
    </tr>	

</tbody>    
</table>
<br>
	
<h4 id="arrpon">Reforço Arrays</h4>
<b>Arrays e strlen</b><br>
<img src="https://github.com/argelcapela/42-trilha-de-fundamentos/blob/main/arrays-pointers/relation-string-arrays-strlen.png?raw=true" width="100%">
<br>	
	
<h4 id="stack-heap">Divisões da Memória</h4>
<b>Tipos de Alocações de Memória das Variáveis:</b><br>
<br>
<img src="https://github.com/argelcapela/42-trilha-de-fundamentos/blob/main/stack-heap/alocacoes.png?raw=true">
<p> </p>
<br>
<b>Como a memória é dividida e organizada?:</b><br><br>
<img src="https://github.com/argelcapela/42-trilha-de-fundamentos/blob/main/stack-heap/organizacao_da_memoria.png?raw=true">
<p>Variáveis locais são guardadas na Stack. <br> Variáveis dinâmicamente alocadas são guardadas na Heap, <i>o tempo de alocação é mais demorado que na Stack. Think of it, quando for projetar programas. Se usar muito Malloc o programa será super lento, existem várias técnicas para gerenciamento de memória, que torna a alocação dinâmica muito mais rápida. </i><br>Variáveis Estáticas são guardadas em outro lugar, nem Heap nem Stack, mas isso é história pra outro dia. XD!</p>
<br><br>    
	
<h2 id="open-read-fd">Open, File Descriptor e Read</h2>
<br>
<i>#include <unistd.h>: read</i><br>
<i>#include <fcntl.h>:  open, read, 'O_RDONLY'</i>
<br>
<b>O que é o nosso queridinho e temido File Descriptor (Descritor de Arquivo)?</b>
<p>É um número. Esse número identifica um arquivo aberto. Toda vez que um arquivo é aberto, é feito um registro em uma tabela, dos arquivos abertos do sistema, cada registro tem um ID, como em SQL, o File Descriptor é esse ID. Simples assim.</p>   

```
int file_descriptor = open("enemy.txt", O_RDONLY);
printf("%d", file_descriptor);
```
<p>Função A variável file_descriptor irá armazenar o fd do arquivo enemy.txt uma vez que ele realmente existe.</p>
<br><br>
<b>E daí?</b> 
<p>Nós podemos realizar várias coisas com um arquivo, escrever nele, ler bytes(caracteres) etc. Sempre que uma função dessa for usada, ela vai pedir o que ? Isso ai, acertou! O bendito File Descriptor, por isso você tem que estar afiado, e clarinho sobre o que é. Tem muito mais por baixo dos panos, mas isso é pra outra hora! XD!</p> 
<br><br>
<b>Me explica as funções OPEN/READ por favor? Beleza, valeu!</b>

<i>Sintax:</i>    
<table>
<tr>
    <td colspan="2">Comando</td>    
    <td>Descrição</td> 
</tr>
    
<tr>
    <td colspan="2">int open(const char *pathname, int flags);</td>    
	<td>
	<ul>
		<li>const char *pathname: Uma constante, ou string normal com a URL do arquivo. </li>
		<li>int flags: é uma constante pré-definida da biblioteca fcntl.h, que indica o tipo de abertura desse arquivo. </li>
		<ul type="circle">
			<li>O_RDONLY: Abrir o arquivo somente para leitura</li>
			<li>Outros tipos não são importantes agora, fica pra próxima!</li>
		</ul>
	</ul>
	</td> 
</tr>
    
<tr>
    <td colspan="2">ssize_t retorno = read(int fd, void *buf, size_t count);</td>    
    <td>
	<ul>
        <li>int fd: FD do arquivo aberto pelo OPEN.</li>
        <li>void *buf: Ele aceita um ponteiro de qualquer tipo, geralmente se chama buffer, é onde será armazenado o que for lido. Geralmente se cria como char* buffer. Ele é void, porque o read faz a leitura dos 'BYTES', não caracteres, não números e sim os BYTES.</li>
        <li>size_t count: Trata-se do famoso BUFFER_SIZE, que isso? É a quantidade de bytes que o read vai ler, nessa chamada da função.</li>
        <li>retorno: A função read retorna um número inteiro que representa uma situação específica da leitura do FD.</li>
	<ul type="circle">
		<li>Número de Bytes lidos : Geralmente é igual ao valor do BUFFER_SIZE, porém pode acontecer do valor ser menor, porque o, offset chega no final do arquivo, antes de ler a quantidade de BYTES correspondentes ao BUFFER_SIZE. </li>
		<li>0 : O Cursor do read, também conhecido como offset, está no final do arquivo, ou passou o final. Ou seja, não tem mais nada pra ler.</li>
		<li>-1 : Erro na leitura, arquivo não existe ou FD inválido.</li>
	</ul>
	    </ul>
        <br><br>
        <p>* O Read funciona como um CURSOR, começa no 0, depois da chamada read, ele avança [count] vezes e fica ali até o programa terminar, é como uma variável estática, guarda a última posição parada, até o programa terminar.</p>
    </td> 
</tr>
</table>  
<br>
    
<br>Exemplo</b>
```
	// lendo o arquivo de texto enemy.txt
	int fd = open("enemy.txt", O_RDONLY);
	
	// lendo os 3 primeiros BYTES desse arquivo, como o buffer é um ponteiro de char, ocorre um pequeno cast, dos bytes para char, ou seja, forma uma string.
	char *buffer;
	int result;
	int BUFFER_SIZE = 3;
	result = read(fd, buffer, BUFFER_SIZE);
	printf("%s", buffer);          
```
<br>Output</b>
```
I w   
```
<br><br>	

<h4 id="runtime-macro">Definir Macro em Tempo de Compilação</h4>

```
$ gcc -D NOME_CONSTANTE=3 fd01.c && ./a.exe
```

<p>-D NOME_CONSTANTE, nós podemos criar uma variável em tempo de compilação, é a mesma coisa que <br> #include NOME_CONSTANTE VALOR</p>
<br><br>

<h2 id="fds">File Descriptor Padrões do Sistema Operacional (Stdin-0, Stdout-1, Stderr-2)</h2>
<img src="https://github.com/argelcapela/42-trilha-de-fundamentos/blob/main/std-fds/std.jpg?raw=true" width="500px" height="300px" alt="File Descriptor Padrões do Sistema">
<p>Do 0 ao 2, esses FD(s) são um pouco abstratos de entender, num primeiro momento, mas eles estão sempre criados. 0 representa o que você digita no teclado, o 1 representa mostrar alguma coisa no terminal de console e 2 representa, todo erro que ocorre ao se executar um comando numa terminal de console. Do 3 em diante os FD(s) passam a representar os arquivos abertos. No momento só o que importa é que 1 representa a saída padrão.</p>
<b></b>
<br><br>

<h2 id="leaks">Resolvendo Erros de Memória</h2>
<b id="debug">Debugando</b>
	
<li>Instalar MinGW, C Run and Compiler, and C/C++ IntelliSense (VSCode Extension) </li>
<li>Para que o Debugger Funcione corretamente é necessário o uso da FLAG -g no gcc.</li>
<li>F10 -> Avança o código para frente.</li>
<li>F11 -> Entra dentro de uma função, quando está em cima dela.</li>
<li>SHIFT + F11 -> Sai de uma função.</li>
<br><br>
	
<b>Que parada é essa de Leak de Memória?</b>
<p>Ocorre quando você aloca dinâmicamente memória (malloc, ft_calloc) e não libera quando essa memória não é mais necessária.</p>
<i>Acostume-se a prestar atenção em todo MALLOC que você utilizar, sempre dê FREE quando essa memória não for mais necessária.</i>
	
<br><br>

<b>Erros Chatos e Frequentes</b>
<table>
<tr>
<td>Erro</td>
<td>Motivo</td>
<td>Valgrind</td>
</tr>
	
<tr>
<td>
	Segmentation Fault<br>
	SIGSEGV<br>
	Core Dump
</td>
<td>
	<ol>
		<li>Tenta acessar uma variável que não tem valor.</li>
	</ol>
</td>
<td></td>
</tr>

	
<tr>
<td>
Buffer Overflow
</td>
<td>
Tenta ultrapassar os limites de um array.
</td>
<td><i>Invalid write of size x</i></td>
</tr>

<tr>
<td>
Memory Leak
</td>
<td>
Malloca memória e não da FREE. 
</td>
<td><i>x bytes in 1 blocks are definitely lost in loss record 1 of 1</i></td>
</tr>
	
<tr>
<td>
Stack Overflow
</td>
<td>
	<ol>
		<li><Malloca tanta memória e/ou cria tantas variáveis que o programa atinge o limite de memória disponível, crasheando!.</li>
		<li>Atinge o limite de memória da Stack ao invéz de alocar dinâmicamente na Heap.</li>
	</ol>
</td>
<td></td>
</tr>
</table>
<br><br>
	
	
<b>Encontrando Erros com o valgrind</b>
```
valgrind --leak-check=full --show-leak-kinds=all ./a.out 
# exibe todos os leaks de memória
```

<br><br>


<h2 id="test">Testes Automatizados</h2>
<b>Tripouille</b>
```
git clone https://github.com/Tripouille/gnlTester
```
<br>
<br></br>

<h2 id="extra">Extra</h2>

```
ulimit -n
```

<p>Informa a quantidade máxima de File Descriptors possível no sistema.</p>

```
@rm -rf *.o 2>/dev/null || true
```

<li>@: esconde o comando.</li>
<li>2>/dev/null || true: esconde os erros se houver.</li>

```
make -C /other/dir
```

```
cd /other/dir && make
```
<p>Executa o Makefile de outro diretório.</p>

<b>Qual a merda da diferença entre esses char* e const??</b>
<table>
<thread>
    <tr>
        <td>Diferença</td>
        <td>char*</td>
        <td>const char*</td>
        <td>char* const</td>
        <td>const char* const</td>
    </tr>
</thead>
<tbody>    
    <tr>
        <td>A Sequência apontada(string) precisa ser?</td>
        <td>String normal ou Constante, tanto faz.</td>
        <td>Constante(Imutável)</td>
        <td>String normal(Mutável)</td>
        <td>Constante(Imutável)</td>
    </tr>
    <tr>
        <td>O ponteiro pode trocar a posição que ele está apontando?</td>
        <td>Sim</td>
        <td>Sim</td>
        <td>Não</td>
        <td>Não</td>
    </tr>
</tbody>    
</table>
<br><br>
      
<h2 id="step-by-step">42-get-next-line Passo a Passo</h2><br>
<a href="https://youtu.be/D9G1VOjN_84"><img src="https://img.youtube.com/vi/D9G1VOjN_84/maxresdefault.jpg" width="100%"></a>
		     
<br><br>
<h2 id="fontes">Fontes</h2>
<li><a href="https://en.wikipedia.org/wiki/Restrict">Restrict 1</a></li>
<li><a href="https://www.youtube.com/watch?v=TBGu3NNpF1Q">Restrict 2</a></li>
<li><a href="https://godbolt.org/">Explore o Assembly de seus códigos em C</a></li> 
<li><a href="https://www.youtube.com/watch?v=pVcuigMNFgA">Stack x Heap</a></li> 
<li><a href="https://man7.org/linux/man-pages/man2/open.2.html">OPEN</a></li> 
<li><a href="https://man7.org/linux/man-pages/man2/read.2.html">READ</a></li> 
<li><a href="https://man7.org/linux/man-pages/man2/write.2.html">WRITE</a></li> 
<li><a href="https://www.youtube.com/watch?v=Fa6Jq0Iue3U">CS50 - Memory</a></li> 
<li><a href="https://www.youtube.com/watch?v=qZ1oQLu7M5Y">Segmentation Fault 1</a></li> 
<li><a href="https://www.youtube.com/watch?v=UOns2zDUv30">Core Dump</a></li> 
<li><a href="https://stackoverflow.com/questions/25798977/returning-string-from-c-function">Returning String Without Memory Leak!</a></li> 
<li><a href="https://pt.wikipedia.org/wiki/Redirecionamento_(computa%C3%A7%C3%A3o)">Redirecionamento</a></li> 
<li><a href="https://superuser.com/questions/370575/how-to-run-make-file-from-any-directory">Executing Makefile in another directory</a></li> 
</div>
