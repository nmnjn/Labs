echo Please enter a Directory
read dir
cd $dir || "No such Directory"
ls *.? || "No files found"
