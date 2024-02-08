with open("depth_data.csv","r") as f:
    all_file = f.read()
    print(all_file)

# the file will be closed above as the "with"
# block has ended.
with open("depth_data.csv","r") as f:
    for line in f:
        print(line.split(","))

        
