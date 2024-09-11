SET YYYY=%DATE:~0,4%
SET MM=%DATE:~5,2%
SET DD=%DATE:~8,2%

SET HH=%TIME:~0,2%
SET MI=%TIME:~3,2%
SET SS=%TIME:~6,2%

git add .
git commit -m "Generally update from dell@tsawke at %YYYY%.%MM%.%DD% %HH%:%MI%:%SS%"
git push