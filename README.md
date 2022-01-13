<!--<div id="portfolio-slideshow-items" class="hide-on-portfolio" visibility="0">
    
</div>
-->

<div class="hide-on-portfolio">
<h1 align="center"> 42_get_next_line </h1>

## :memo: Descrição:
O Objetivo é criar uma função em C, dentro de algumas restrições, que leia uma linha de um Descritor de Arquivo ( é mais fácil entender na prática), em outras palavras , de um arquivo de texto. Cada vez que essa função get_next_line() é chamada, deve retornar a linha seguinte, até o final do arquivo. Excelente para praticar lógica, ponteiros e leaks(vazamentos) de memória. MUUITOS LEAKS DE MEMÓRIA.
</div>

<div class="col-12">

## :wrench: Tecnologias utilizadas:<br>
<div style="display: inline_block">
    <img align="center" alt="gel-Js" height="30" width="40" src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg">

</div>

<div class="col-12">
    
## :books: Funcionalidades:<br>
<table class="special-border">
<tr>
<th colspan="2">Mandatory</th>
</tr>
<tr>
    <td colspan="2">Ler todos os bytes de um descritor de arquivos até encontrar um \n</td>
</tr>
</table>
    
</div>

<div class="col-12">

## :rocket: Rodando o projeto:<br>
<table class="special-border">
<tr>
    <td colspan="2">Abra o terminal, entre na pasta do GNL e digite o comando:</td>
</tr>
<tr>
    <td colspan="2">gcc -D BUFFER_SIZE=2 get_next_line.c get_next_line.h get_next_line_utils.c -g && ./a.exe</td>
</tr>
</table>
  <br>
<li>Repositório Github: <a href="https://github.com/argelcapela/42_get_next_line">Link</a></li>
<li>Intra 42SP: <a href="https://projects.intra.42.fr/42cursus-get_next_line">Link</a></li>
 
	
	
</div>
<div class="col-12">

## :soon: Implementação futura:<br>
    
<li>Nada em mente por enquanto.</li>
    
</div>
<div class="col-12">
    

## :handshake: Colaboradores:<br>
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
    
## :dart: Status do projeto:<br>

<li>Em desenvolvimento.</li>
    
</div>
<br><br><br><br><br><br>
<div class="col-12">
    
## :memo: Aprendi com esse projeto<br>
	
https://docs.google.com/spreadsheets/d/1Ewfq-R65Ymko8qteJmLQJcv46l1OeaD-m8QBJ4s8TEs/edit#gid=0
	
<li><a href="#static-variable">Variáveis Estáticas</a></li>
<li><a href="#restrict">Restrict</a></li>
<li><a href="#stack-heap">Stack & Heap</a></li>
<li><a href="#open-read-fd">Open/Read/File Descriptor</a></li>
<li><a href="#leaks">Leaks de Memória</a></li>
<li><a href="#fds">File Descriptor Padrões do Sistema Operacional (Stdin-0, Stdout-1, Stderr-2)</a></li>
<li><a href="#runtime-macro">Definir Macro em Tempo de Compilação</a></li>
<hr>
<li><a href="#algoritmo">Entendendo a GNL</a></li>
<li><a href="#step-by-step">Step By Step</a></li>
<li><a href="#test">Testando o projeto</a></li>
<hr>
<li><a href="#debugger">Debugando Projetos</a></li>
<hr>
<li><a href="#fontes">Fontes</a></li>
    
<h1 id="static-variable">Variáveis Estáticas</h1>
<b>O que são Variáveis Estáticas ,pelo amor do pai ?</b>
<p>Uma variável que você coloca um valor nela, e esse valor, fica ali, não importa o que aconteça, <u>até o programa acabar, ou até você atribuir outro valor aquela variável.</u></p>
<br><br>
    
<b>Coisas relevantes que eu deva saber dessa jóssa?</b>
<ul>
    <li>Ela começa valendo 0, mesmo sem nada ser atribuído.</li>
    <li>A variável estática é inicializada somente uma vez durante o programa, não importa se uma função passa várias vezes pela linha que declara a variável estática, depois da primeira vez que essa linha é executada, nas outras vezes ela será "ignorada".</li>
</ul>
<br><br>
    
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
</tbody>    
</table>
<br><br>

<b>Diferentes combinações de Ponteiros + Const</b>
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
<h1 id="restrict">Restrict Type Qualifier</h1>
<b>O que é esse tróço?</b>
<p>Ele é usado somente em ponteiros, ele é uma promessa, diz para o compilador que esse ponteiro é o único ponteiro que está apontando para o valor apontado, é o único caminho par acessar o valor apontado. Como assim Júnior? Vamos lá! Imagina que temos um ponteiro chamado (int* restrict num1) que está apontando para o número um número 10 qualquer, o restrict promete para o compilador que nenhum outro ponteiro está apontando para esse mesmo número 10. O restrict não afeta nada no código em si, mas sim, no modo como o Assembly, ou o compilador executa o código, se a promessa do restrict não for respeitada, vários erros podem ser gerados no código, porém se usado corretamente, pode tornar uma aplicação muito mais rápida. <br> Bora de exemplo?</p>

```
void updatePtrs(size_t *ptrA, size_t *ptrB, size_t *val)
{
  *ptrA += *val;
  *ptrB += *val;
}
```
``` 
; Código Assembly RISC Machine (hipotético)
ldr r12, [val]     ; Carrega/"Copia" a memória alocada apontada por [val] no registrador r12
ldr r3, [ptrA]     ; Carrega/"Copia" a memória alocada apontada por [ptrA] no registrador r3
add r3, r3, r12    ; Executa uma soma entre os registradores: r3 = r3 + r12.
str r3, [ptrA]     ; Pega o valor do registrador r3 e joga na memória alocada apontada por ptrA.
ldr r3, [ptrB]     ; Espera até a operação anterior terminar / Carrega o valor da variável [ptrB] no registrador r3
ldr r12, [val]     ; Carrega/"Copia" a memória alocada apontada por [val] no registrador r12 de novo. Por que?
                   ; porque se o ponteiro val ou ptrA apontarem para o mesmo local, depois da soma feita anteriormente, o valor de val será diferente, então, o compilador
                   ; precisa ler de novo para garantir que o valor está correto.
add r3, r3, r12    ; Executa a soma r3 = r3 + r12
str r3, [ptrB]     ; Pega o valor do registrador r3 e joga na memória alocada apontada por ptrA.
``` 
<p>O Compilador sem o restrict faz uma verificação pra saber se o valor de val mudou, caso val apontasse para o mesmo bloco de memória que os demas ponteiros. </p>
    
    
```
void updatePtrs(size_t *restrict ptrA, size_t *restrict ptrB, size_t *restrict val)
{
  *ptrA += *val;
  *ptrB += *val;
}
```
``` 
; Código Assembly RISC Machine (hipotético)
ldr r12, [val]  ; Aqui o registrador r12 carrega o bloco de memória apontado por [val] somente uma vez. Porque o restrict, garante pro compilador que esse ponteiro é o único                     ; caminho ou seja, esse valor não vai mudar nas outras operações.
ldr r3, [ptrA]  ; Carrega os blocos de memória apontados pelos ponteiros [ptrA] e [ptrB] nos respectivos registradores r3,r4.
ldr r4, [ptrB]
add r3, r3, r12 ; Executa as operações de adição.
add r4, r4, r12
str r3, [ptrA]  ; Executa as operações de atualização.
str r4, [ptrB]
``` 
<p>Agora quando, eu coloco o restrict, o compilador não precisa fazer verificações de consistência, ele vai direto ao ponto, só carrega e executa as operações.</p>    
<i>Nesse exemplo simples, pode parecer pouco relevante porém, o uso correto do restrict em aplicações mais complexos torna a aplicação mais rápida.</i>

<h1 id="stack-heap">Stack & Heap</h1>
<b>Tipos de Alocações de Memória das Variáveis:</b><br>
<br>
<img src="https://github.com/argelcapela/42-trilha-de-fundamentos/blob/main/stack-heap/alocacoes.png?raw=true">
<p> </p>
<br>
<b>Como a memória é dividida e organizada?:</b><br><br>
<img src="https://github.com/argelcapela/42-trilha-de-fundamentos/blob/main/stack-heap/organizacao_da_memoria.png?raw=true">
<p>Variáveis locais são guardadas na Stack. <br> Variáveis dinâmicamente alocadas são guardadas na Heap, <i>o tempo de alocação é mais demorado que na Stack. Think of it, quando for projetar programas. Se usar muito Malloc o programa será super lento, existem várias técnicas para gerenciamento de memória, que torna a alocação dinâmica muito mais rápida. </i><br>Variáveis Estáticas são guardadas em outro lugar, nem Heap nem Stack, mas isso é história pra outro dia. XD!</p>
    
<h1 id="open-read-fd">Open/Read/File Descriptor</h1>
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

<h1 id="runtime-macro">Definir Macro em Tempo de Compilação</h1>

```
$ gcc -D NOME_CONSTANTE=3 fd01.c && ./a.exe
```

<p>-D NOME_CONSTANTE, nós podemos criar uma variável em tempo de compilação, é a mesma coisa que <br> #include NOME_CONSTANTE VALOR</p>
<br><br>

<h1 id="fds">File Descriptor Padrões do Sistema Operacional (Stdin-0, Stdout-1, Stderr-2)</h1>
<img src="https://github.com/argelcapela/42-trilha-de-fundamentos/blob/main/std-fds/std.jpg?raw=true" width="500px" height="300px" alt="File Descriptor Padrões do Sistema">
<p>Do 0 ao 2, esses FD(s) são um pouco abstratos de entender, num primeiro momento, mas eles estão sempre criados. 0 representa o que você digita no teclado, o 1 representa mostrar alguma coisa no terminal de console e 2 representa, todo erro que ocorre ao se executar um comando numa terminal de console. Do 3 em diante os FD(s) passam a representar os arquivos abertos. No momento só o que importa é que 1 representa a saída padrão.</p>
<b></b>
<br><br>

<h1 id="leaks">Leaks de Memória & Valgrind</h1>

<b>Que parada é essa de Leak de Memória?</b>
<p>Ocorre quando você aloca dinâmicamente memória (malloc, ft_calloc) e não libera quando essa memória não é mais necessária.</p>
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
	ou<br>
	SIGSEGV	
</td>
<td>
	<p>Tentar acessar um bloco de memória ilegal.</p>
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
Malloca tanta memória e/ou cria tantas variáveis que o programa atinge o limite de memória disponível, crasheando!.
</td>
<td></td>
</tr>
</table>
<br><br>
<b>Encontrando Erros de memória invisíveis com o Valgrind</b>

```
valgrind --leak-check=full ./a.exe/out     # execute o seu programa compilado com o valgrind
					   # leia as mensagens de erro uma por uma e tente corrigí-las.
```

<br><br>

<h1 id="algoritmo">Qual o lógica desse projeto GNL?</h1>
<br><br>


<h1 id="step-by-step">Step By Step</h1>
<br><br>


<h1 id="test">Testando o projeto</h1>
<table class="special-border">
<tr>
    <td colspan="2">Abra o terminal, entre na pasta do GNL e digite o comando:</td>
</tr>
<tr>
    <td colspan="2">gcc -D BUFFER_SIZE=2 get_next_line.c get_next_line.h get_next_line_utils.c -g && ./a.exe</td>
</tr>
</table>
<br><br>
<b>Testadores GNL</b>
<img src="https://github.com/argelcapela/gnl/blob/main/test/testadores/status%20testadores%20gnl.png?raw=true" alt="status dos testadores">
<br><br>

<ul>
	<li><a href="https://github.com/Tripouille/gnlTester">Tripouille</a>(Muito bom!)</li>
	<li><a href="https://github.com/charMstr/GNL_lover">GNL_Lover</a>(...)</li>
	<li><a href="https://github.com/mrjvs/42cursus_gnl_tests">42cursur_gnl_tests</a>(...)</li>
	<li><a href="https://github.com/Hellio404/Get_Next_Line_Tester">Helio</a>(...)</li>
</ul>
<br><br>
<b>Principais testes da GNL (Moulinete)</b>

<table>
	<tr>
		<td>Nome</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>41_no_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>41_with_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>42_no_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>42_with_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>43_no_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>43_with_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>alternate_line_nl_no_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>alternate_line_nl_with_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>big_line_no_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>big_line_with_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>empty</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>multiple_line_no_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>multiple_line_with_nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>multiple_nlx5</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
	<tr>
		<td>nl</td>
		<td>Descrição</td>
		<td>Solução</td>
	</tr>
</table>
<br></br>
<h1 id="debugger">Debugando Projetos</h1>
<h1 id="extra">Extra</h1>
<b>Entendendo melhor os caracteres</b>


<br><br>
<h1 id="fontes">Fontes</h1>
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


</div>
