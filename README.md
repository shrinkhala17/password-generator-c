# 🔐 Password Generator in C

A simple, beginner-friendly command-line password generator written in C. Customize your password by length and character types, and generate a strong random password instantly.

---

## 📋 Features

- Choose your desired **password length** (4–128 characters)
- Toggle any combination of character types:
  - 🔠 Uppercase letters `A-Z`
  - 🔡 Lowercase letters `a-z`
  - 🔢 Numbers `0-9`
  - ❗ Special characters `!@#$%^&*()-_=+[]{}|;:,.<>?`
- **Input validation** — re-prompts on invalid entries
- **Safe fallback** — defaults to lowercase if no character type is selected
- Clean, well-commented code — great for learning C

---

## 🖥️ Demo

```
========================================
        🔐 C Password Generator
========================================

Enter password length (4 – 128): 12

Which character types should be included?
  Uppercase letters (A-Z)   (y/n): y
  Lowercase letters (a-z)   (y/n): y
  Numbers          (0-9)    (y/n): y
  Special chars (!@#…)      (y/n): y

========================================
  Your generated password:

  .eCp9$I<,G0*

========================================
  Length  : 12 characters
  Options : Uppercase Lowercase Numbers Specials
========================================

Tip: Store your password in a secure password manager!
```

---

## 🚀 Getting Started

### Prerequisites

You need a C compiler installed:

- **Linux/macOS** — GCC is usually pre-installed. Check with `gcc --version`.
- **Windows** — Install [MinGW](https://www.mingw-w64.org/) or use [WSL](https://learn.microsoft.com/en-us/windows/wsl/).

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/password-generator-c.git
   cd password-generator-c
   ```

2. **Compile**
   ```bash
   gcc password_generator.c -o password_generator
   ```

3. **Run**
   ```bash
   # Linux / macOS
   ./password_generator

   # Windows
   password_generator.exe
   ```

---

## 📁 Project Structure

```
password-generator-c/
│
├── password_generator.c   # Main source file
└── README.md              # Project documentation
```

---

## 🧠 How It Works

| Step | What happens |
|------|-------------|
| 1 | User enters a password length between 4 and 128 |
| 2 | User selects which character types to include |
| 3 | Selected character sets are combined into one pool using `strcat()` |
| 4 | A `for` loop picks random characters from the pool using `rand() % poolSize` |
| 5 | The finished password is printed to the terminal |

The random number generator is seeded with `srand(time(NULL))` so every run produces a different result.

---

## 🔧 Customization

Want to extend the project? Here are some ideas:

- [ ] Generate multiple passwords at once
- [ ] Add a password **strength meter**
- [ ] Save generated passwords to a `.txt` file
- [ ] Exclude ambiguous characters (e.g. `0`, `O`, `l`, `1`)
- [ ] Add a **repeat / regenerate** option without restarting

---

## 📚 Concepts Covered (for learners)

This project is a great hands-on example of:

- `#define` macros for constants
- `scanf` for user input
- `strcat` and `strlen` for string manipulation
- `rand()` and `srand()` for random number generation
- Input validation with `while` loops
- Functions with return values (`askYesNo`)
- Arrays and null-terminated C strings

---

## 📄 License

This project is licensed under the [MIT License](LICENSE) — free to use, modify, and distribute.

---

## 🙌 Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request.

1. Fork the project
2. Create your feature branch: `git checkout -b feature/my-feature`
3. Commit your changes: `git commit -m 'Add my feature'`
4. Push to the branch: `git push origin feature/my-feature`
5. Open a Pull Request

---

> 💡 **Tip:** Always store your passwords in a trusted password manager like [Bitwarden](https://bitwarden.com/) or [1Password](https://1password.com/).
