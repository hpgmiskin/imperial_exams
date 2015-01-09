#C++ Exam Reference

This directory contain `reference_sheet.tex` which can be built by **LaTeX** to produce a two page reference sheet.

##To Build

Install [MiKTeX](http://miktex.org/) for Windows or [MacTex](https://tug.org/mactex/) for Mac. Ensure that 'pdflatex' can be accessed from the command line. For Linux users pdflatex is often included as standard.

**Install Python** if its not already installed

Follow this [tutorial](http://joequery.me/guides/install-python27-pip-virtualenv/) on installing Python2.7 with pip.

**Install Pygments** to allow syntax highlighting

```
$ pip install Pygments
```

If using a UNIX based operating system in the current directory call the makefile:

```
$ make
```

Alternatively use the following command at the command line in the current directory:

```
> pdflatex -shell-escape reference_sheet.tex
```

This will build the `.tex` file into a `.pdf` that can be viewed.

##Forking

Please feel free to fork this repository and suggest changes