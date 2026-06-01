*** UID:0001RS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# User Status Resources

## Status

- Confidence: strong for resource names and owner classes.
- Related file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Related classes: [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md), [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md), [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- Evidence basis: IDA MCP literal/xref/decompile checks.

## Resource Set

| Resource | Used by | Notes |
| --- | --- | --- |
| `9X11FONT.BIN` | all three status panes | Numeric glyph table loaded during construction and freed during cleanup. |
| `USERSTAT.EPF` | `UserStatusPane::OnPaint` | Newer/EPF status panel frame path. |
| `USERSTAT.EPD` | `UserStatusPane::OnPaint`, `OldUserStatusPane::OnPaint` | Legacy/fallback status panel frame path. |
| `ITEMINV.PAL` | `UserStatusPane::OnPaint` | Palette paired with the newer `USERSTAT.EPF` path. |
| `NPAL7.PAL` | `UserStatusPane::OnPaint`, `OldUserStatusPane::OnPaint` | Palette for legacy panel and nation/totem frame draws. |
| `NATION.EPD` | `UserStatusPane::OnPaint`, `OldUserStatusPane::OnPaint` | Nation icon/text frame resource. |
| `TOTEM.EPD` | `UserStatusPane::OnPaint`, `OldUserStatusPane::OnPaint` | Totem/spirit icon frame resource. |
| `CLASS.EPD` | `UserStatusPane::OnPaint`, `OldUserStatusPane::OnPaint` | Class icon frame resource. |
| `NPAL5.PAL` | `UserStatusPane::OnPaint`, `OldUserStatusPane::OnPaint` | Palette used for class icon drawing. |
| `BAR.EPD` | `UserStatusPane::OnPaint`, `OldUserStatusPane::OnPaint` | Legacy status bar frame resource. |
| `BAR.EPF` / `BAR.PAL` | status-bar render helper, owner still needs review | Direct xrefs go through `0x0041ba40-0x0041bdce`, not the status-pane method itself; keep ownership cautious until the helper is tied back cleanly. |
| `COMMA.EPF` / `COMMA.PAL` | `UserStatusPane2::OnPaint` | Grouping separator sprites for large numeric values. |

## Resource Ownership

These resources should remain with the local status panel source area when direct xrefs support that owner. `COMMA` is directly tied to `UserStatusPane2`; `BAR.EPF` / `BAR.PAL` are status-meter-like but currently route through a separate helper and need another pass before treating them as exclusively owned by `UserStatusPane2`. Broader reuse should be documented in separate resource pages if later xrefs show other owners.

## IDA MCP Evidence

- UTF-16 `9X11FONT.BIN` at `0x0061682c` is referenced from constructors including `0x005b83b0-0x005b8526`, `0x005bab00-0x005babf7`, and `0x005bda40-0x005bdb63`, matching the three status-pane families.
- UTF-16 `USERSTAT.EPF` at `0x00630edc` is referenced from `0x005b8c70-0x005b9d6a`; UTF-16 `USERSTAT.EPD` at `0x00630ef8` is referenced from both `0x005b8c70-0x005b9d6a` and `0x005be520-0x005bf10d`.
- UTF-16 status icon resources are verified at `0x00630f14` (`NATION.EPD`), `0x00630f2c` (`TOTEM.EPD`), `0x00630f40` (`CLASS.EPD`), `0x00630f5c` (`BAR.EPD`), `0x006152ec` (`NPAL7.PAL`), `0x00610fd0` (`NPAL5.PAL`), and `0x0061c964` (`ITEMINV.PAL`), with xrefs into `0x005b8c70-0x005b9d6a` and/or `0x005be520-0x005bf10d`.
- ASCII `COMMA.EPF` at `0x006247f0` and `COMMA.PAL` at `0x006248cc` are referenced from `0x005baf80-0x005bbe15`, directly supporting the `UserStatusPane2` compact-number path.
- UTF-16 `BAR.EPF` at `0x0060db00` and `BAR.PAL` at `0x0060db10` are referenced by `0x0041ba40-0x0041bdce`; this helper needs ownership tracing before the `BAR` pair is treated as uniquely part of `UserStatusPane2`.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md)
- [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md)
- [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md)

## Changes

- What existed before: the page was scored unevaluated, cited generated source, and treated `BAR.EPF` / `BAR.PAL` as direct `UserStatusPane2` resources.
- Changed to: scored `COMPLETION:72` / `CONFIDENCE:84`, replaced generated-source wording with IDA MCP evidence, and downgraded `BAR.EPF` / `BAR.PAL` ownership to a helper-owned/open item.
- Summary and evidence: IDA confirms the status-pane font, status frame, icon, palette, and `COMMA` resources; score stays conservative because `BAR` helper ownership and exact frame semantics still need a focused pass.
