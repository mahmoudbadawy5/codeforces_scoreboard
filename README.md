# codeforces_scoreboard
A tool to build IOI-based scoreboard from multiple contests of codeforces with IOI 2017- scoring style.
It gets submissions from the contest and recalculates the score according to the following:

For each subtask its score equals the smallest score a case got. The score of a subtask for a participant is the maximum score across all submissions.
The score for a problem is the summation of scores of subtasks.

## Requirements
1) You should download required packaged using pip command:
  ```pip3 install -r requirements.txt```
2) You must have a codeforces account with manager access to all contests the scoreboard needs to show.
3) You must have an api key which can be aquired from here: https://codeforces.com/settings/api


## How to setup
1) You need to make a copy of `config.example.py` as `config.py` and fill the required data.
2) You need for each problem of the contests the `problem.xml` file.
  - All files must be present at the folder called `data`
  - You need to rename the files with contest number and problem index like : 1A.xml, where contest index is the 1-based index of the contest as ordered in contestIds in the config.py file.
3) Additionally, you can provide `users.txt` file in the `data` folder to show participiants names in the same format as domain users described here: https://codeforces.com/blog/entry/51787 , password and contest numbers are irrelevant so you can leave them empty.


## How to run
Run it as a flask program:
```flask run```

## Reset submissions
Delete all files in log folder