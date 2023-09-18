# Define the command you want to run
$command = "g++"
$output = "-o main"
$inputFile = ".\main.cpp"
$links = "-lfreeglut -lglew32 -lopengl32 -lglu32"

echo "$command $output $inputFile $links"

Set-Location -Path "C:\\Users\\Lenovo Admin\\Desktop\\CG\\lab02"


# Run the command
Invoke-Expression "$command $output $inputFile $links"
