# Generating Apriltags for printing and Gazebo
* Follow [this instruction](https://www.tutorialspoint.com/articles/how-to-install-imagemagick-on-ubuntu) to install `ImageMagick`
* Configure `STARTING_TAG`, `ENDING_TAG`, `RESIZE_PDF` in `convert_png_to_pdf.py`
* `python convert_png_to_pdf.py`
    - This will create separate `pdf` and `png` for each tag and a montage of all the selected tags
* Print the `pdf`s using **actual size**