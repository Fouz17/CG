# Define the command you want to run
$command = "g++"
$output = "-o main"
$headers = ""
$inputFile = ".\Tooth.cpp"
$links = "-lfreeglut -lglew32 -lglu32 -lopengl32"

echo "$command $output $inputFile $links"

Set-Location -Path "C:\\Users\\Lenovo Admin\\Desktop\\CG\\lab 12"


# Run the command
Invoke-Expression "$command $output $inputFile  $links"
