# Week 2

- [Leetcode](#leetcode)
- [Jobs Stuff](#jobs-stuff)
  - [CV](#cv)
  - [LinkedIn](#linkedin)
  - [Tracker Links](#tracker-links)
  - [General Advice](#general-advice)
- [C](#c)
- [Git + Terminal](#git--terminal)
  - [Basic Terminal Commands](#basic-terminal-commands)
  - [Git Setup](#git-setup)
  - [Git](#git)
    - [Creating a new repo](#creating-a-new-repo)
    - [Other commands](#other-commands)
  - [Other Information](#other-information)
    - [Package Managers](#package-managers)
      - [MacOS](#macos)
      - [Windows](#windows)
      - [Linux](#linux)
    - [Misc](#misc)

## Leetcode

- <https://leetcode.com/problems/merge-strings-alternately/>
- <https://leetcode.com/problems/greatest-common-divisor-of-strings/>

## Jobs Stuff

### CV

- [Jake's Resume Template](https://www.overleaf.com/latex/templates/jakes-resume/syzfjbzwjncs)
- Education Section (Sixth Form / Secondary School + UCL (Degree + Courses + Dates)). Scholarships + awards?
- Experience (Internships, Research, etc.)
- Projects (Literally anything - links including GitHub. Very important to have a good README)
- Remember to include skills used/learned for each experience/project
- Technical Skills (Languages, Frameworks, Libraries, other tools, etc.)

### LinkedIn

- LinkedIn (all basic information + connections)
- Cold-emailing startups (shouldn't be too large or too small)
- Jobs section (software intern) - not easy apply. Through the website if an option.

### Tracker Links

- [Summer SWE Internships](https://bit.ly/trackertech)
- [Other Trackers (including Spring Weeks)](https://the-trackr.com/trackers/)

### General Advice

- Interviews (different types of questions). Hireviews
- Change CV + LinkedIn to be 2027 Grad Year for whoever is on MEng

## C

We covered pointers in today's session. Refer to [random.c](random.c).

## Git + Terminal

### Basic Terminal Commands

- `.`: means current directory.
- `..`: means directory above / up one level.
- `.<name>`: means a hidden file/folder where `<name>` is the name of the file/folder.
- `*`: this is a wildcard which essentially means any/all.
  - example: `*.txt` would refer to all text files.
- `cd`: stands for change directory and moves you to a different folder.
- `ls`: stands for list and lists all the files and folders in the current directory.
  - example: `ls -la` to view all files/folders including hidden ones.
- `touch`: creates a new file.
- `mkdir`: creates a new directory.
- `grep`: allows searching for text or regular expressions in a file or directory.
  - example: `grep "github" README.md`.
- `cat`: stands for concatenate and prints the contents of a file to the terminal screen.
- `less`: same as `cat` but allows the user to scroll the file. `more` is similar to this.
- `|`: this is the pipe redirect. It takes the output of the command before it and puts it as the input for the command after it.
  - example: `cat README.md | grep "github"`.
- `>>`: This is the append redirect operator which appends the results of the command before it to the file after it.
  - example: `echo "hello world" >> README.md`.
- `>`: This is the write redirect operator. Similar to `>>`, except it overwrites the contents of the file.
- `<<` and `<`: Same as `>>` and `>`, just redirects the other way. You will likely not use this very often.
- `man`: stands for manual and allows you to see all the options for a given command.
  - example: `man grep`.
- `mv`: stands for move and moves a file or directory to a different location. Also commonly used to rename a file.
  - example: `mv README.md ../CONFIG.md`.
- `cp`: stands for copy and is used in the same way as `mv`, but it creates a copy of the file/directory instead of renaming/moving it.
- `which`: lets you figure out where the command is located and being run from.
  - example: `which python`.

### Git Setup

This only needs to be done once to setup your system. Replace `<github_username>` and `<github_email>` with yours below:

```sh
git config --global user.name "<github_username>"
git config --global user.email "<github_email>"
```

### Git

#### Creating a new repo

1. Go to [GitHub](https://github.com/) and click on the green `New` button to create a new repository.
2. Name the repo and set the privacy to public/private as needed.
3. Select yes for the option to automatically create the `README` file.
4. Make sure to add the relevant `gitignore` for your project e.g. search for `Python` if it's a Python project.
   - After setting up the repo, refer to [gitignore.io](https://www.toptal.com/developers/gitignore/) to automatically create a larger gitignore with more coverage for different OSes, IDEs, or Programming Languages.
5. Create the project, the repository, then click on the green `Code` button and copy the link displayed.
   - Make sure you are in the `Local` and `HTTPS` tabs after clicking the button.
6. Go to your terminal, navigate to the directory where you want the project folder to be (using `cd` and `ls`), and type `git clone <repo_link>`, replacing `<repo_link>` with the link you copied.
7. `cd` into the project folder, and **congratulations! you have created a git repo and cloned it locally to work on it!**

#### Other commands

All the commands written below should be **prefixed** with `git` e.g. `add` is actually `git add`.

- `add <files>`: adds the changes made in the `<files>` to the staging area.
  - example: `git add .` adds all changes in the current directory.
- `commit -m "<message>"`: commits the changes in the staging area to the local repository with `<message>` as a comment.
  - example: `git commit -m "updated README with git commands"`.
- `push -u <remote> <branch>`: pushes the changes in the local repository's relevant `<remote>` and `<branch>` to the online repository.
  - example: `git push -u origin main`.
  - > NOTE: unless you start doing really advanced things with git, the `<remote>` will almost always be `origin`.
- `pull <remote> <branch>`: syncs any changes made to the online repository to the local repository.
  - example: `git pull origin main`.
- `branch <name>`: creates a new branch called `<name>`.
  - example: `git branch new_branch`.
- `checkout <branch_name>`: switches the current working directory to the branch with `<branch_name>`.
  - example: `git checkout main`.
- `merge <branch_name>`: merges the branch with `<branch_name>` to the currently checked out branch.
  - example: `git merge new_branch`.
  - > NOTE: when merging, you may get merge conflicts. If this happens, open the github project folder in VSCode and click on "resolve" in the bottom right for any files that are highlighted in red. Then, for each conflict select whether you want to keep the current code or the incoming changes.

### Other Information

#### Package Managers

If you haven't already, ensure that your computer has some sort of package manager.

##### MacOS

For Mac, follow the instructions [here](https://brew.sh/) to install Homebrew.

##### Windows

For Windows, follow the instructions [here](https://github.com/microsoft/winget-cli) to install Winget, or [here](https://chocolatey.org/) to install Chocolatey.  
Also, make sure you have WSL (Windows Subsystem of Linux) or something that can run Unix commands installed as your life will become **WAY** easier this way.

> NOTE: I am a professional non-\*nix hater, so *seriously* consider moving to a Mac (or Linux) lol.

##### Linux

If you have a Linux computer, *PLEASE BE MY FRIEND*. Ok, but in all seriousness, make sure you know which package manager your flavour of Linux uses - `apt` / `yum` / something else.

#### Misc

If you love configuring your own setups, look into [tmux](https://github.com/tmux/tmux/wiki) and [emacs](https://www.gnu.org/software/emacs/).  
Anyone who knows me well knows just how much time I've wasted on this stuff, but I seriously enjoy it. It won't help you in any way, apart from maybe speeding up your workflow, but I genuinely find it fun to mess with these kinds of things. Plus, it's cool to look at.  
If you ever do decide to look into these, please let me know. I need someone to geek out about this stuff with PLEASE.
