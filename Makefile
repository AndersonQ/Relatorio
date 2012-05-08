all:
	pdflatex relatorio.tex
	pdflatex relatorio.tex
##	bibtex relatorio
##	pdflatex relatorio.tex
##	pdflatex relatorio.tex
	rm *.log *.out *.toc *.aux *.bbl *.blg *.brf -vf

clean:
	rm -vf relatorio.aux relatorio.log relatorio.out relatorio.toc

cleanall: clean
	rm -vf relatorio.pdf
