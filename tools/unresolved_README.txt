unresolved.py
=============

Purpose
-------

unresolved.py indexes generated, decompiler-style, or otherwise non-human
names that remain in project documentation. Examples include raw symbols such
as `dword_69C110`, `sub_49DF20`, `DAT_0067a744`, `this+0x26c`,
`meth_0x4b14c0`, `cls_0x469180`, `aAn1Epf`, and `nullsub_18`.

The goal is to make placeholder names visible as a project-level cleanup queue
without confusing them with real project names. For example, NexusTK has real
DAT archive classes and modules such as `DATFile`, `DATFileMgr`,
`DATIndexVector`, and `DATArchive`; those are not matched by the DAT filter.
Only generated address labels such as `DAT_0067a744` are indexed.

The tool scans Markdown files under direct `by-*` documentation folders. It
does not scan root-level docs, `project-level`, `tools`, or generated report
files. It is separate from validator.py and does not create UID headers,
completion lines, or UID reference annotations.

Files
-----

- `tools/unresolved.py`
  User-facing scanner and resolved-name registry tool.

- `tools/unresolved.json`
  Scanner configuration. It defines report output paths, scan extensions,
  excluded directory/file suffix rules, and regex filters.

- `tools/unresolved.ini`
  Tool-owned data file. It stores the latest scan state, filter counts,
  matched token indexes, occurrence context data, resolved-name mappings,
  temporary resolved-name aliases, and resolved coverage summaries. Do not
  hand-edit it during normal use; use the `resolve`, `rename`, `unresolve`,
  `alias`, and `unalias` commands for resolved names.

- `project-level/-unresolved.md`
  Generated report for unresolved or not-yet-covered placeholder names.

- `project-level/-resolved.md`
  Generated report for placeholder names that have a recorded human resolved
  name in `tools/unresolved.ini`.

- `project-level/-resolved-multple-aliases.md`
  Generated compact report for resolved placeholder names that currently have
  one or more temporary aliases.

Generated Reports
-----------------

`project-level/-unresolved.md` lists generated tokens that still need naming
work or document coverage. Each token section includes a compact summary:

```text
- References: X Occurrences: Y Markdown link/path occurrences: Z
```

Each referenced file line includes every occurrence found in that file:

```text
- `by-memory/example.md` | [before] > `token` > [after] (kind, Lx:Cy) | ...
```

The `before` and `after` values are 20 characters of context from each side of
the token. Newlines are shown as `\n`, pipes are escaped, and backticks in the
context are normalized to apostrophes so the report remains readable.

Occurrence `kind` values:

- `text`: normal document text.
- `markdown_link`: the token is inside a Markdown inline/reference link span.
- `path`: the token is inside a path-like span, such as a filename or `.md`
  path.

These kinds are important for future replacement tooling. Injecting text into a
`markdown_link` or `path` occurrence can break links or filenames.

When `Ignore_Not_Reconstructable` is enabled in `tools/unresolved.json`, report
output hides file references and occurrences from Markdown files explicitly
marked:

```text
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The scan still reads those files and `tools/unresolved.ini` still keeps their
raw match and occurrence data. The setting only changes what appears in the
generated Markdown reports.

`project-level/-resolved.md` lists resolved-name records in this form:

```text
### `generated_token` -> `ResolvedHumanName`
```

For each file where the generated token still appears, the report lists the
canonical resolved name, any temporary aliases, and marks the file as:

- `covered`: the file contains both the generated token and the resolved name.
- `pending`: the file contains the generated token but does not contain the
  resolved name.

If aliases exist for the resolved name, a file is also considered `covered`
when it contains any alias for that resolved name.

Each resolved-report file row also includes a `matched:` field. This field
shows exactly which canonical resolved name or alias was found in that file,
for example:

```text
- `by-memory/example.md` | `covered` | matched: `g_realName` (resolved) | ...
- `by-memory/example.md` | `covered` | matched: `g_oldName` (alias) | ...
```

Use this to track whether coverage came from the final canonical name or only
from a temporary alias that still needs cleanup.

Resolved-name report entries keep the same occurrence context format as the
unresolved report.

`project-level/-resolved-multple-aliases.md` is a compact alias-only report.
It lists only resolved generated tokens with aliases, using this form:

```text
| Filtered item | Resolved name | Aliases |
| --- | --- | --- |
| `generated_token` | `g_realName` | `g_oldName`, `g_otherName` |
```

This file is refreshed with the other project-level unresolved/resolved
reports during scan apply.

Resolved-Name Behavior
----------------------

Resolved names are stored in `tools/unresolved.ini` under `[resolved_names]`.
Temporary aliases are stored under `[resolved_aliases]`. They do not edit
documentation files by themselves. They only change report classification.

Resolved names and alias names must be valid C++ variable identifiers under
40 characters. They may contain letters, numbers, and underscores, must not
start with a number, and must not be C++ keywords. Invalid input fails with:

```text
Must be valid c++ varaiable name under 40 characters.
```

When scanning finds a generated token that has a resolved name:

1. For each file containing the generated token, unresolved.py checks whether
   the resolved name or any alias for that resolved name also appears in that
   same file.
2. If the resolved name or one of its aliases appears in that file, that file
   is omitted from the generated token's `-unresolved.md` entry.
3. If every file containing the generated token also contains the resolved
   name, the token disappears entirely from `-unresolved.md`.
4. The token and all of its file references appear in `-resolved.md`, marked
   as `covered` or `pending`.

This lets `-unresolved.md` stay focused on open naming work while
`-resolved.md` tracks known mappings and where documentation still contains
old generated aliases.

Commands
--------

Dry-run full scan:

```powershell
python unresolved.py
python unresolved.py scan
python unresolved.py --mode full
```

Apply full scan and write `tools/unresolved.ini`,
`project-level/-unresolved.md`, `project-level/-resolved.md`, and
`project-level/-resolved-multple-aliases.md`:

```powershell
python unresolved.py --mode full --apply
```

Dry-run one file for inspection:

```powershell
python unresolved.py --mode file --file ..\by-memory\example.md
```

File-scoped scans are dry-run only. Do not use `--apply` with `--mode file`;
that would replace the global project-level indexes with one file's results.
Run `python unresolved.py --mode full --apply` to refresh generated reports.

Record a resolved name:

```powershell
python unresolved.py resolve dword_69C110 g_someHumanName
```

`resolve` creates only. If the token already has a resolved name, the command
fails and does not overwrite it:

```text
already named: dword_69C110 = existingName
```

Rename an existing resolved name:

```powershell
python unresolved.py rename dword_69C110 g_betterHumanName
```

`rename` updates only. If the token does not already have a resolved name, the
command fails:

```text
not resolved: dword_69C110
```

Remove an existing resolved name:

```powershell
python unresolved.py unresolve dword_69C110
```

`unresolve` deletes only. If the token is not currently resolved, the command
fails:

```text
not resolved: dword_69C110
```

`unresolve` also removes any aliases that point to the removed resolved name,
because aliases are temporary and are only meaningful while the resolved-name
record exists.

Add a temporary alias for an existing resolved name:

```powershell
python unresolved.py alias g_realName g_oldOrAlternateName
```

The alias target can be either the canonical resolved name or an existing alias
for that resolved name. For example, after:

```powershell
python unresolved.py resolve dword_69C110 g_realName
```

this command records `g_oldOrAlternateName` as another temporary spelling for
the same target:

```powershell
python unresolved.py alias g_realName g_oldOrAlternateName
```

Aliases are intended only as temporary compatibility markers for documents that
currently use multiple human names for the same generated token. They should be
removed once the documentation is normalized.

Remove a temporary alias:

```powershell
python unresolved.py unalias g_oldOrAlternateName
```

Alias safety rules:

- An alias target must already resolve to an existing resolved name.
- Resolved names and alias names must be valid C++ variable identifiers under
  40 characters.
- An alias name cannot already exist as another alias.
- An alias name cannot be the canonical resolved name for any generated token.
- An alias name cannot be a generated token that already has a resolved name.
- A new resolved name cannot be created or renamed to a name that already
  exists as an alias.
- A resolved name must be unique across generated tokens.
- When a resolved name is renamed, aliases pointing to the old name are moved
  to the new canonical name.
- When a resolved name is removed, aliases pointing to it are removed too.

Override paths:

```powershell
python unresolved.py --root E:\NTK\GhidraBridge\source-3\project-documentation --apply
python unresolved.py --config tools\unresolved.json --ini tools\unresolved.ini --apply
python unresolved.py --output project-level\-unresolved-test.md --resolved-output project-level\-resolved-test.md --multiple-aliases-output project-level\-resolved-multple-aliases-test.md --apply
```

Show verbose token file counts:

```powershell
python unresolved.py --verbose
```

Configuration
-------------

`tools/unresolved.json` controls scan behavior.

Important fields:

- `output`
  Documentation-root-relative path for the unresolved report.

- `resolved_output`
  Documentation-root-relative path for the resolved report.

- `multiple_aliases_output`
  Documentation-root-relative path for the compact resolved names with aliases
  report.

- `scan_extensions`
  File extensions to scan. Currently Markdown only.

- `exclude_by_folder_names`
  Direct documentation folders ignored before recursive scanning. Use this for
  top-level `by-*` folders that should not contribute unresolved-name report
  data, such as `by-meta`, `by-external-research`, and
  `by-project-structure`.

- `exclude_directory_names`
  Directory names ignored during recursive scanning. Use this for generic
  nested folder names such as `.git`, `__pycache__`, or `auto-generated`.

- `exclude_file_suffixes`
  Filename suffixes ignored during scanning, such as `.bak`.

- `filters`
  Ordered regex filters. Each filter has `name`, `enabled`, `pattern`, and
  `description`.

- `Ignore_Not_Reconstructable`
  Boolean output filter. When `true`, `-unresolved.md` and `-resolved.md` hide
  references from files whose metadata explicitly says
  `RECONSTRUCTABLE:FALSE` or `RECONSTRUCTABLE:0`, matching validator false
  semantics. Files with blank, missing, or true reconstructable metadata are
  still shown. This does not change scanning or INI data capture.

Do not add overly broad filters that match human-authored address-suffixed
names. Names such as `InitializeMainUiGraph_004F7D10`,
`ApplicationHelper_4A6C40`, and `HasDATEntry_49C700` can be legitimate
documentation names and should not be treated as unresolved merely because
they end with an address. Prefer prefix-specific generated-name filters such
as `sub_[hex]`, `dword_[hex]`, `DAT_[hex]`, `cls_0x[hex]`, or `meth_0x[hex]`.

INI Data Sections
-----------------

`tools/unresolved.ini` is rewritten during apply scans. Main sections:

- `[state]`
  Latest generated timestamp and scan totals.

- `[filters]`
  Per-filter raw match counts.

- `[matches]`
  Generated token to semicolon-separated file list.

- `[occurrence_summary]`
  Per-token occurrence totals, protected Markdown link/path totals, and file
  totals.

- `[occurrences]`
  Per-token JSON occurrence arrays. Each occurrence records file, line, column,
  kind, before context, and after context.

- `[resolved_names]`
  User-managed generated-token to resolved-name mappings. Mutated by
  `resolve`, `rename`, and `unresolve`.

- `[resolved_aliases]`
  Temporary alias-name to canonical resolved-name mappings. Mutated by `alias`,
  `unalias`, `rename`, and `unresolve`.

- `[resolved_coverage]`
  Latest scan summary for resolved-name mappings.

Safe Workflow
-------------

1. Run a full apply scan:

```powershell
python unresolved.py --mode full --apply
```

2. Pick a token from `project-level/-unresolved.md`.

3. Research the real human name in the relevant by-folder docs and, when
   needed, IDA/MCP or Wave evidence.

4. Record the mapping:

```powershell
python unresolved.py resolve dword_69C110 g_realName
```

5. Run the scanner again:

```powershell
python unresolved.py --mode full --apply
```

6. Use `project-level/-resolved.md` to see which files are covered or still
   pending. Use the occurrence contexts and `markdown_link` / `path` markers
   before doing any automated replacement.

Validator Interaction
---------------------

validator.py does not scan `project-level` files and will reject them in file
mode because they are outside direct `by-*` folders. unresolved.py reports
under `project-level` are therefore not given UID headers and are not touched
by validator UID/reference injection. The only validator-owned project-level
file is `project-level/-auto-completion-stats.md`.
