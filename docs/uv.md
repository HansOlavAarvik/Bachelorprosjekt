# Intro

[uv](https://docs.astral.sh/uv/) er eit vertkøy som fjerner hodebryet med manuelle venvs, req filer, som kan gjere at utviklermiljøet til folk kjem ut av sync og skaper konflikter.
Alt du skal trenge å gjere for å installere deps og køyre [hello.py](../hello.py) er å installere uv og bruke denne kommandoen 
- `uv run hello.py`

## [Installer uv for ditt operativsystem ](https://docs.astral.sh/uv/getting-started/installation/)
  
Fleire installasjonsmoglegheiter tilgjengeleg. `winget` er eit greit alternativ for windows

`winget install --id=astral-sh.uv  -e`

- Restart Kodeappen din, om du får `uv not recognized` feilmeldinga.

## [Dependecies](https://docs.astral.sh/uv/concepts/projects/dependencies/)

Legg til og fjern *avhengigheiter (deps)*, dette vil endre `pyproject.toml`

- `uv add pandas`
- `uv remove pandas`

Oppdater ein dep ved å køyre
- `uv lock --upgrade-package pandas`

## Filer med meir

uv bruker ein del filer for å halde orden på prosjektet, 
les denne [introen](https://docs.astral.sh/uv/concepts/projects/layout/) for meir informasjon om dei