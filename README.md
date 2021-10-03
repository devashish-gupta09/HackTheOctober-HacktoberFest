<h1 align="center"> HacktoberFest </h1>


<h4>[ In development Phase ] 
[ Hacktoberfest-Accepted ] </h4>
<h2> 


<div align="left">
<a href="https://github.com/devashish-gupta09/HackTheOctober-HacktoberFest"><img src="https://sloc.xyz/github/devashish-gupta09/HackTheOctober-HacktoberFest" alt="LOC"/></a>
<a href="https://github.com/devashish-gupta09/HackTheOctober-HacktoberFest"><img src="https://img.shields.io/github/stars/devashish-gupta09/HackTheOctober-HacktoberFest" alt="Stars Badge"/></a>
<a href="https://github.com/devashish-gupta09/HackTheOctober-HacktoberFest/network/members"><img src="https://img.shields.io/github/forks/devashish-gupta09/HackTheOctober-HacktoberFest" alt="Forks Badge"/></a>
<a href="https://github.com/devashish-gupta09/HackTheOctober-HacktoberFest/graphs/contributors"><img alt="GitHub contributors" src="https://img.shields.io/github/contributors/devashish-gupta09/HackTheOctober-HacktoberFest?color=2b9348"></a>
<a href="https://devashish-gupta09/HackTheOctober-HacktoberFest"><img src="https://badges.frapsoft.com/os/v2/open-source.svg" alt="Open Source"/></a>
</div>
<a href="https://open.vscode.dev/organization/repository"><img src="https://open.vscode.dev/badges/open-in-vscode.svg" alt="Open in Visual Studio Code"/></a>
</div>


# Contribution is fun! 🧡




<!-- ![image](https://github.com/SauravMukherjee44/Aec-Library-Website/blob/7cf3bafebd9e1a6d6fa95f40822cbcdd28a4005b/assets/images/aec.PNG) -->

In order to make a hassle-free environment, I implore you all (_while contributing_) to follow the instructions mentioned below!

Happy Submissions :slightly_smiling_face:

<h1> Contributing Guidelines </h1>

## Basics of Git and GitHub

### Git & GitHub

Before we proceed, it's better to know the difference between Git and Github. Git is a version control system (VCS) that allows us to keep track of the history of our source code , whereas GitHub is a service that hosts Git projects. 

We assume you have created an account on Github and installed Git on your System.

Now enter your name and E-mail (used on Github) address in Git, by using following command.

`$ git config --global user.name "YOUR NAME"`
` $ git config --global user.email "YOUR EMAIL ADDRESS"`
This is an important step to mark your commits to your name and email.

<br />

### Fork a project

You can make a copy of the project to your account. This process is called forking a project to your Github account. On Upper right side of project page on Github, you can see -

<p align="center">  <img  src="https://i.imgur.com/P0n6f97.png">  </p>
Click on fork to create a copy of project to your account. This creates a separate copy for you to work on.

<br />

<br />

### Clone the forked project

You have forked the project you want to contribute to your github account. To get this project on your development machine we use clone command of git.

`$ git clone https://github.com/SauravMukherjee44/Aec-Library-Website.git` <br/>
Now you have the project on your local machine.

<br />

### Add a remote (upstream) to original project repository

Remote means the remote location of project on Github. By cloning, we have a remote called origin which points to your forked repository. Now we will add a remote to the original repository from where we had forked.

`$ cd <your-forked-project-folder>`
`$ git remote add upstream https://github.com/SauravMukherjee44/Aec-Library-Website.git` <br/>
You will see the benefits of adding remote later.

<br />

### Synchronizing your fork

Open Source projects have a number of contributors who can push code anytime. So it is necessary to make your forked copy equal with the original repository. The remote added above called Upstream helps in this.

`$ git checkout main`
`$ git fetch upstream`
`$ git merge upstream/main`
`$ git push origin main` <br/>
The last command pushes the latest code to your forked repository on Github. The origin is the remote pointing to your forked repository on github.

<br />

### Create a new branch for a feature or bugfix

Usually, all repositories have a main branch that is regarded to be stable, and any new features should be developed on a separate branch before being merged into the main branch. As a result, we should establish a new branch for our feature or bugfix and go to work on the issue. 

`$ git checkout -b <feature-branch>`
This will create a new branch out of master branch. Now start working on the problem and commit your changes.

`$ git add --all`
`$ git commit -m "<commit message>"`
The first command adds all the files or you can add specific files by removing -a and adding the file names. The second command gives a message to your changes so you can know in future what changes this commit makes. If you are solving an issue on original repository, you should add the issue number like #35 to your commit message. This will show the reference to commits in the issue.

<br />

### Push code and create a pull request

You now have a new branch containing the modifications you want in the project you forked. Now, push your new branch to your remote github fork. 

`$ git push origin <feature-branch>`
Now you are ready to help the project by opening a pull request means you now tell the project managers to add the feature or bug fix to original repository. You can open a pull request by clicking on green icon -

<p align="center">  <img  src="https://i.imgur.com/aGaqAD5.png">  </p>

Remember your upstream base branch should be main and source should be your feature branch. Click on create pull request and add a name to your pull request. You can also describe your feature.

Congratulations! You've already made your first contribution.🥳

Good Luck for your journey


<h1 align=center> OUR VALUABLE CONTRIBUTORS✨ </h1>
<p align="center">
  
	
<a href="https://github.com/devashish-gupta09/HackTheOctober-HacktoberFest/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=devashish-gupta09/HackTheOctober-HacktoberFest" />
</a>

<h1 align=center>Happy Coding 👨‍💻 </h1>

---

</div>

© 2021 Devashish and contributors\
This project is licensed under the [**MIT license**](https://github.com/SauravMukherjee44/Aec-Library-Website/blob/main/LICENSE).

[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)
