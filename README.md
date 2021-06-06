# GEMP - UECE - ICPC Library [DRAFT]

Code library for competitive programming purposes.
The script to generate the pdf file was from [Competitive-Programming-Notebook](https://github.com/PauloMiranda98/Competitive-Programming-Notebook).

## Dependencies

It's necessary to install python and latex.

```script
sudo apt-get install python
sudo apt install texlive-latex-extra
sudo apt-get install latexmk
```

## Execution

```script
cd build
python3 generate_pdf.py
```

## Add

Create a file with the new code and add it in the `$categoria/` with `name_of_the_algorithm.cpp`. To add it to the PDF file just add it to `contents.md` in the respective `**category**` in the following format: `- [x] [name_in_the_pdf]($category/name_of_the_algorithm.cpp)`

## Remove

Remove the file's name from `$categoria/` in the `contents.md`.