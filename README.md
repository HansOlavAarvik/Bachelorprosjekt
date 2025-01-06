# Bachelorprosjekt
Kode til bachelorprosjekt

Her skal det stå om prosjektet og korleis ein bruker det. 

## Utviklingsoppsett

### [uv](https://docs.astral.sh/uv/)

Dette er eit verktøy for å handtere prosjekter, eit essensielt verktøy for å handtere venvs, avhengigheitar, bygging m.m. når ein lager større prosjekt.

> 🚀 A single tool to replace pip, pip-tools, pipx, poetry, pyenv, twine, virtualenv, and more.

Sjå [uv.md](docs/uv.md) for meir informasjon



### Ruff

uv installerer også ruff som eit utviklingsverktøy. Som fjerner stil- og formatteringsfeil i koden.
Ekvivalent til black/flake, som er linter og formatteringsfikseverktøy

Bruk det med å køyre

`ruff check`

`ruff check --fix` for å fikse problema den finn. 