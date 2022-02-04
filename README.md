<!--<div id="portfolio-slideshow-items" class="hide-on-portfolio" visibility="0">
    
</div>
-->

<div class="hide-on-portfolio">

<div align="center">
	<p><i>"O Senhor ama o esforço porque o esforço traz recompensas que não viriam de outra forma."</i><br><b>Russel M. Nelson</b></p>
<br><br>
	<img src="https://github.com/argelcapela/argelcapela.rf.gd/blob/main/assets/img/galeria/portfolio_img_42-get-next-line.jpg?raw=true" width="250px">
</div>
<br><br>
	
# ✨ O que é a Get Next Line ?
<b>Trata-se de uma função que lê uma linha de um arquivo. </b><br>

Cada vez que a função é chamada, deve retornar a linha seguinte, até ler todo o arquivo. Excelente para praticar lógica, ponteiros e leaks(vazamentos) de memória.
</div>

<div class="col-12">

# 🔧 Tecnologias utilizadas:<br>
<div style="display: inline_block">
    <img align="center" alt="gel-Js" height="30" width="40" src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg">

</div>

<div class="col-12">

# 🚀 Rodando o projeto:<br>
<b>Links:</b>
<li>Repositório Github: <a href="https://github.com/argelcapela/42-get-next-line">Link</a></li>
<li>Intra 42SP: <a href="https://projects.intra.42.fr/42cursus-get_next_line">Link</a></li>
<br><br>
<b> Depois de clonar o repositório, dentro da pasta test, pode-se executar esses comandos e testar rapidamente o projeto:</b><br><br>
	
```bash
# Clone o Repositório
	
$ git clone https://github.com/argelcapela/42-get-next-line

# Entre na pasta 42-get-next-line depois em test
	
$ cd 42-get-next-line
$ cd test

# Você pode compilar o projeto manualmente ou
# usar os comandos pré-definidos do Makefile:
	
$ make lin 	#Compila e executa no ambiente linux
$ make lincat 	#Compila e executa no ambiente linux com o cat -e no retorno (quebras de linha serão exibidas com $)
$ make win	#Compila e executa no ambiente windows
$ make leak	#Compila e executa o valgrind, ambiente linux, com todas as principais flags para buscar leaks de memória!
$ make tester	#Executa o tester Tripoulle!
```
<br>
<b> Ou se preferir pode testar manualmente criando um main próprio, a seguir temos um exemplo de main para testar a GNL:</b><br><br>

```
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	// test #1
	int fd = open("arquivo a ser lido", O_RDONLY);
	char *resposta = get_next_line(fd);

	while(resposta)
	{
		printf("%s", resposta);
		free(resposta);
		resposta = get_next_line(fd);
	}

	return(0);
}

```
	
<br>
😎compilando...<br>
	
```bash
$ gcc get_next_line.c get_next_line.h get_next_line_utils.c main.c && ./a.out	
```
	
</div>
<br>
<div class="col-12">
    
# 📌 O que eu aprendi e como foi desenvolvido esse projeto?<br>
<b>1) Conhecimento adquiridos para fazer a função ler linha por linha</b><br>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#algoritmo">Lógica GNL</a></li>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#static-variable">Variáveis Estáticas</a></li>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#arrpon">Arrays e Ponteiros</a></li>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#stack-heap">Divisões da Memória</a></li>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#open-read-fd">Open, File Descriptor, Read</a></li>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#runtime-macro">Definir Macro em Tempo de Compilação</a></li>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#debug">Como usar o Debugger (GDB/VSCODE)</a></li>
<br>
	
<b>2) Leaks e Testers</b>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#leaks">Erros de Memória</a></li>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#test">Testes automatizados</a></li>
<br>
	
<b>3) Brinde</b>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#step-by-step"> 42-get-next-line Passo a Passo</a></li>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#outras">Outras Coisas Legais</a></li>
<li><a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md#fontes">Fontes</a></li>
</div>
<br>	
	
<div class="col-12">
	
# 🤝 Colaboradores:<br>
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
<br><br>
<i>Obrigado Especial 🎁 a Welton, Krebs, João, Moacir e outros cadetes que me auxiliaram no entendimento dos procedimentos para desenvolver esse projeto. Vocês são tops! Quando eu crescer quero ser como vocês rsrs Sucesso! 👽✌😁👍 </i>
</div>
	
<div class="col-12">
	
# 📅 Status do projeto:<br>
<img src="https://github.com/argelcapela/argelcapela.rf.gd/blob/main/assets/icons/finalizado.png?raw=true" width="250px" height="200px">
</div>
	
<br>

<div class="col-12">
	
# 📋 Nota:<br>
<img src="https://github.com/argelcapela/42-trilha-de-fundamentos/blob/main/assets/nota-125.png?raw=true" width="150px" height="150px" alt="nota gnl">
</div>
	
<br>

<div class="col-12">
	
# 🐛 Erros:<br>
<p>Identificou um erro? Por favor me informe! ou fique a vontade para criar um *issue* aqui no Github e contribuir.</p>
<p>Também fique a vontade para opinar, criticar, xingar, elogiar etc. Para mim é tudo a mesma coisa, fonte de crescimento pessoal. Eu não sei tudo, mas estou buscando ser um profissional 1% melhor a cada dia.</p>
</div>
	
<div class="col-12">
<p>Não esqueça de dar um ⭐️ se você gostou, ou se esse repositório te ajudou de alguma maneira, isso irá me ajudar muito! Obrigado, você é top! 😁👍</p>
</div>
	

	
	
	
<br><br><br>
<br><br><br>
<br><br>
	
<div align="center">

# 👑
	
</div>    
<br><br>

<a href="https://youtu.be/D9G1VOjN_84"><img src="https://img.youtube.com/vi/D9G1VOjN_84/maxresdefault.jpg" width="100%"></a>
<br><br>
<i>Fique a vontade para conferir meu estudo sobre a 42-get-next-line, clicando no icone bonitinho abaixo. <br> Ah! Se quiser deixe um comentário também: 😎</i><br><br>
<a href="https://github.com/argelcapela/42-get-next-line/blob/main/42-get-next-line.md" target="_BLANK"><img src="https://i.imgur.com/z4ULooG.png" alt="conferir estudo"></a>
<br>
</div>   
