<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a id="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![42 Profile][42]][42-url]


<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/timurlog/tree">
    <img src="assets/logo.svg" alt="Logo" width="120" height="120">
  </a>

<h3 align="center">Tree</h3>

  <p align="center">
    Reimplementation of the Unix 'tree' command in C
    <br />
    <a href="https://github.com/timurlog/tree"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/timurlog/tree/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    &middot;
    <a href="https://github.com/timurlog/tree/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#linuxmacos-installation">Installation</a></li>
        <li><a href="#update">Update</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]]()

This project is a C reimplementation of the Unix `tree` command, which recursively displays a directory structure.

It aims to provide a better understanding of file handling and directories.

The program scans a given path (or `.` by default) and outputs a formatted tree view.

The project is designed to be simple and portable.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

   [![C][C]][C-url]

   [![Makefile][Makefile]][Makefile-url]

   [![Shell][Shell]][Shell-url]


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

Here are the steps to follow to install `tree` on your 42 Linux/macOS machine.

### Linux/macOS Installation

Execute this Command

   ```sh
   bash -c "$(curl -fsSL https://raw.github.com/timurlog/tree/main/bin/install.sh)"
   ```

### Update

Execute this Command

   ```sh
   bash -c "$(curl -fsSL https://raw.github.com/timurlog/tree/main/bin/update.sh)"
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

### The basic syntax is:

   ```sh
   tree [options] [directory]
   ```

### Options Available in my `tree` Command

| Options                    | Description                                                            |
|----------------------------|------------------------------------------------------------------------|
| `--help`                   | Show help.                                                             |
| `--version`                | Displays the version of the tree.                                      |
| `--update`                 | Updates the tree command.                                              |
| `directory name`           | Displays the directory tree hierarchy.                                 |
| `-d`                       | Lists only directories.                                                |
<!-- | `-t`                       | Sorts the output by last modification time rather than alphabetically. | -->
<!-- | `-s`                       | Print the size of each file along with the name.                       | -->
<!-- | `-r`                       | Sort the output in reverse alphabetic order.                           | -->


_For more examples, please refer to the [Documentation](https://www.geeksforgeeks.org/tree-command-unixlinux/)_

_This project does not implement all the options available in the original `tree` command_

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [x] Basic Syntax `tree [directory]` Command
- [ ] Basic Syntax of `tree [options]` Command
    - [x] `--help` Show help
    - [x] `--version` Displays the version of the tree
    - [x] `--update` Updates the tree command
    - [x] `-d` Lists only directories
    - [ ] `-t` Sorts the output by last modification time rather than alphabetically
    - [ ] `-s` Print the size of each file along with the name
    - [ ] `-r` Sort the output in reverse alphabetic order

See the [open issues](https://github.com/timurlog/tree/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Top contributors:

<a href="https://github.com/timurlog/tree/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=timurlog/tree" alt="contrib.rocks image" />
</a>

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Timur Logie - [42 Profile](https://profile.intra.42.fr/users/tilogie) - tilogie@student.s19.be

Project Link: [https://github.com/timurlog/tree](https://github.com/timurlog/tree)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [tree Command Doc](https://www.geeksforgeeks.org/tree-command-unixlinux/)
* [Choose a License](https://choosealicense.com/)
* [README.md Template](https://github.com/othneildrew/Best-README-Template)
* [Francinette install.sh Inspiration](https://github.com/xicodomingues/francinette/blob/master/bin/install.sh)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/timurlog/tree.svg?style=for-the-badge
[contributors-url]: https://github.com/timurlog/tree/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/timurlog/tree.svg?style=for-the-badge
[forks-url]: https://github.com/timurlog/tree/network/members
[stars-shield]: https://img.shields.io/github/stars/timurlog/tree.svg?style=for-the-badge
[stars-url]: https://github.com/timurlog/tree/stargazers
[issues-shield]: https://img.shields.io/github/issues/timurlog/tree.svg?style=for-the-badge
[issues-url]: https://github.com/timurlog/tree/issues
[license-shield]: https://img.shields.io/badge/License-MIT-green?style=for-the-badge
[license-url]: https://github.com/timurlog/tree/blob/main/LICENSE.txt
[42]: https://img.shields.io/badge/-Profile-black.svg?style=for-the-badge&logo=42&colorB=555
[42-url]: https://profile.intra.42.fr/users/tilogie
[product-screenshot]: assets/screenshot.png
[C]: https://img.shields.io/badge/C-blue?style=for-the-badge&logo=c&logoColor=white
[C-url]: https://www.c-language.org/ 
[Makefile]: https://img.shields.io/badge/Makefile-0779c1?style=for-the-badge&logo=gnubash&logoColor=white
[Makefile-url]: https://makefile.site/
[Shell]: https://img.shields.io/badge/Shell-Bash-4EAA25?style=for-the-badge&logo=gnubash&logoColor=white
[Shell-url]: https://bash-shell.net/
