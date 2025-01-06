from typing import Any # Døme på problem ruff kan fikse
try:
   import pyjokes
   HAS_OPTIONAL = True
except ImportError:
   HAS_OPTIONAL = False

def main():
    if HAS_OPTIONAL:
        print(pyjokes.get_joke())
    else:
        print("👌👌👌")


if __name__ == "__main__":
    main()
