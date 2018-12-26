#!/usr/bin/python
from __future__ import division
from IPython import embed
import subprocess, math, shutil, os

STARTING_TAG = 0
ENDING_TAG = 19

# RESIZE_PDF = 708
# 708 is the default number for Personal Robotics Lab
# The output is a 4.8 cm tag surrounded by 0.6 cm of padding (6 cm square total).
# https://github.com/personalrobotics/kinbody_detector

# RESIZE_PDF = 472
# 472: The output is a 3.2 cm tag surrounded by 0.4 cm of padding (4 cm square total).
# 472 = 708/3*2
# This is for honda

RESIZE_PDF = 236
# 236: The output is a 1.6 cm tag surrounded by 0.2 cm of padding (2 cm square total).
# 236 = 708/3*1
# This is for Ankit's table setting


RESIZE_PNG = 1000
# 1000 we need the png to be 1000 * 1000 - very high resolution
# so that the tag is clear in Gazebo

INPUT_DIR = "tag36h11"
OUTPUT_DIR = "ready_to_print_size_" + str(RESIZE_PDF)
if os.path.isdir("./" + OUTPUT_DIR):
    shutil.rmtree("./" + OUTPUT_DIR)
os.makedirs("./" + OUTPUT_DIR)

# Since we are using 300 DPI, the letter size is 2550x3300
# http://www.a4papersize.org/a4-paper-size-in-pixels.php
# Somehow the montage is larger than the A4 page, so we need to make 80%.
LETTER_WIDTH = 2550*0.8
LETTER_HEIGHT = 3300*0.8

# When we montage all the tags into 1 pdf, the border between
# each row and col of tags.
MONTAGE_BORDER = 10
MONTAGE_NUM_ROWS = int(math.floor(LETTER_HEIGHT\
        / (RESIZE_PDF + 2*MONTAGE_BORDER)) - 1)
MONTAGE_NUM_COLS = int(math.floor(LETTER_WIDTH\
        / (RESIZE_PDF + 2*MONTAGE_BORDER)) - 1)
MONTAGE_FILE_NAME = "montage"

if __name__ == "__main__":
    for i in range(STARTING_TAG, ENDING_TAG + 1):
        index = "%05d" % i
        # https://stackoverflow.com/questions/89228/calling-an-external-command-in-python?page=1&tab=votes#tab-top

        # 1. We use PDF to print
        # https://github.com/personalrobotics/kinbody_detector
        """
        Use ImageMagick to convert the .png file to a .pdf that is suitable for printing:
		$ convert tag36_11_00XXX.png -density 300 -interpolate Nearest -filter point -resize 708x708 tag36_11_00XXX.pdf
		The output is a 4.8 cm tag surrounded by 0.6 cm of padding (6 cm square total).
        """
        cmd = "convert ./"+INPUT_DIR+"/tag36_11_"+index+".png -density 300 "\
                +"-interpolate Nearest -filter point "\
                +"-resize "+str(RESIZE_PDF)+"x"+str(RESIZE_PDF)+" "\
                +"./"+OUTPUT_DIR+"/tag36_11_"+index\
                +"_size"+str(RESIZE_PDF)+".pdf"
        ret_val = subprocess.check_output(cmd, shell=True)
        if ret_val == '':
            print "Successfully convert to " + "./" + OUTPUT_DIR + "/tag36_11_" + index + "_size" + str(
                RESIZE_PDF) + ".pdf"

        # 2. We load PNG into Gazebo
        cmd = "convert ./"+INPUT_DIR+"/tag36_11_"+index+".png -density 300 "\
                +"-interpolate Nearest -filter point "\
                +"-resize "+str(RESIZE_PNG)+"x"+str(RESIZE_PNG)+" "\
                +"./"+OUTPUT_DIR+"/tag36_11_"+index\
                +"_size"+str(RESIZE_PNG)+".png"
        ret_val = subprocess.check_output(cmd, shell=True)
        if ret_val == '':
            print "Successfully convert to " + "./" + OUTPUT_DIR + "/tag36_11_" + index + "_size" + str(
                RESIZE_PNG) + ".png"

    # 3. Combine pdfs into montage
    """
    montage *pdf -background black -tile 3x4 -geometry +0+0 -border 5 -bordercolor black output.pdf
    https://stackoverflow.com/questions/31405803/tile-concatenate-high-resolution-pdf-files-with-imagemagick
    http://www.imagemagick.org/Usage/montage/
    """
    output_file_path = "./" + OUTPUT_DIR + "/" + MONTAGE_FILE_NAME + ".pdf"
    cmd = "montage ./"+OUTPUT_DIR+"/*.pdf" + " -background black "\
            +"-tile " + str(MONTAGE_NUM_COLS) + "x"\
            + str(MONTAGE_NUM_ROWS) + " -geometry +0+0 -border "\
            + str(MONTAGE_BORDER) + " -bordercolor black "\
            + output_file_path
            # + "-page Letter -density 300 "\
    ret_val = subprocess.check_output(cmd, shell=True)
    if ret_val == '':
        print "Successfully montage to " + output_file_path
        print "The tag number is 0,1,... per row."




# embed()
