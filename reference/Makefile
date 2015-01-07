NAME = reference_sheet

$(NAME).pdf: $(NAME).tex
	pdflatex -shell-escape $(NAME).tex

clean:
	rm $(NAME).aux $(NAME).log

open:
	open $(NAME).pdf