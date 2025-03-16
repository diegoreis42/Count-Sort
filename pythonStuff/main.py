#!/usr/bin/python3

import argparse as ap
import rand_files_gen as rfg

parser = ap.ArgumentParser(
            prog="RandFilesGen",
            description="Create random number files in various formats",
            epilog="Ever tried, ever failed"
            )

parser.add_argument("-f", "--file", dest="fileName", help="Name of the file to be created")
parser.add_argument("-n", "--numbers", dest="nrandNum", type=int, help="Quantity of random numbers to be created, 'n' also defines the range of numbers")
parser.add_argument("-O", "--ordered", action="store_true", help="Say if the sequence must be ordered")
parser.add_argument("-A", "--automatic", action="store_true", help="Automatically generate files with 100, 1000, 10000, 100000 and 1000000 numbers")

if __name__ == "__main__":
    
    args = parser.parse_args()
    if args.automatic:
        rfg.autoGen(args.ordered)
    else:
        rfg.writeRandFile(args.fileName, args.nrandNum, args.ordered)
    


                            
