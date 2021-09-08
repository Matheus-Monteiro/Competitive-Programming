# GEMP - UECE - ICPC Library

Code library for competitive programming purposes.

## On the Dependencies

It's necessary to install python and latex.

```script
sudo apt-get install python
sudo apt install texlive-latex-extra
sudo apt-get install latexmk
```

## On the Updates

If you have added any new algorithms to the repository run the commands below to update the contents.md file.

```script
cd latex
g++ -std=c++17 extract.cpp
./a.out > ../contents.md
```

## On the PDF generation

After updating the contents.md file, execute the command below to generate the PDF.

```script
cd latex
python3 generate_pdf.py
```