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
	
```bash
# 1) Clone o projeto
$ git clone https://github.com/argelcapela/42-get-next-line.git 
	
# 2) Entre na pasta 'app'
$ cd app	
	
# 3) Crie uma função main dentro de get_next_line.c ou um arquivo main.c dentro da pasta app, e compile tudo junto.
$ touch main.c
$ gcc get_next_line.c get_next_line.h get_next_line_utils.c main.c

# 4) Execute
$ ./a.out
	
```

```C
/* main.c */
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
	
</div>
<br>
<div class="col-12">
    
# 📌 O que eu aprendi e como foi desenvolvido esse projeto?<br>
EM BREVE AGUARDE

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
