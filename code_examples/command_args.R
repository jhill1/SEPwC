args = commandArgs(trailingOnly=TRUE)
count = 1
for (arg in args) {
    print(paste0(count, " " , arg))
    count <- count + 1
}

