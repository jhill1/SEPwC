library(argparse)

parser <- argparse.ArgumentParser()
parser$add_argument("square", type=int,
                    help="display a square of a given number")
parser$add_argument("-v", "--verbosity", type=int, choices=[0, 1, 2],
                    help="increase output verbosity", default=0)
parse$add_argument("--output_file")
args <- parser$parse_args()
square <- args.square
output_file <- args.output_file

if (square <= 0) {
    print("Please provide a positive integer")
    exit()
}
answer <- square**2
if (args$verbosity == 2) {
    print(paste0("The square of ",square, "equals ", answer))
} else if (args.verbosity == 1) {
    print(paste0(square,"^2 == ",answer))
} else {
    print(answer)
}

