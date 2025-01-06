# Bachelorprosjekt
Kode til bachelorprosjekt

Her skal det stå om prosjektet og korleis ein bruker det. 

## Utviklingsoppsett

### [uv](https://docs.astral.sh/uv/)

> 🚀 A single tool to replace pip, pip-tools, pipx, poetry, pyenv, twine, virtualenv, and more.


1. [Installer uv for ditt operativsystem ](https://docs.astral.sh/uv/getting-started/installation/)
    - Fleire installasjonsmoglegheiter tilgjengeleg. `winget` er eit greit alternativ for windows

        `winget install --id=astral-sh.uv  -e`
    - Restart Kodeappen din, om du får `uv not recognized` feilmeldinga.

### Ruff

uv installerer også ruff som eit utviklingsverktøy. Som fjerner stil- og formatteringsfeil i koden.
Ekvivalent til black/flake, som er linter og formatteringsfikseverktøy

Bruk det med å køyre

`ruff check`

`ruff check --fix` for å fikse problema den finn. 