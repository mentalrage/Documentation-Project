*** UID:0001RS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# User Status Resources

## Status

- Confidence: very strong for direct status-pane resource names, owner classes, pane-variant routing, current literal xrefs, current DAT entries, and several source-visible frame-index roles; medium for missing legacy `.EPD` payloads, final shared `BAR.EPF` / `BAR.PAL` helper ownership, and visual frame validation.
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
| `BAR.EPF` / `BAR.PAL` | compact status paint path plus shared status-bar render helpers, owner still needs review | 2026-06-14 IDA xrefs include `UserStatusPane2::OnPaint` sites and separate helper families at `0x0041ba40` and `0x0056ce50`; keep ownership cautious until the helper/source split is tied back cleanly. |
| `COMMA.EPF` / `COMMA.PAL` | `UserStatusPane2::OnPaint` | Grouping separator sprites for large numeric values. |

## Package Provenance

2026-06-16 A002 parsed the fixed DAT entry tables across `E:\2026\Resources\Read_Only\NexusTK\Data`, searched exact loose names under `E:\2026\Resources`, and repeated a UTF-16 executable literal scan for the status resource names.

| Resource | Current package evidence | Payload/frame notes |
| --- | --- | --- |
| `9X11FONT.BIN` | `bint0.dat`, entry index `0`, offset `1,092`, size `3,069`; no loose duplicate found. | Shared status/UI numeric glyph payload. |
| `USERSTAT.EPF` | `bint2.dat`, entry index `120`, offset `17,126,356`, size `7,336`; no loose duplicate found. | EPF header reports `1` frame of `171x42`. |
| `BAR.EPF` / `BAR.PAL` | `bint0.dat` entries `3`/`4`, offsets `27,377` / `37,261`, sizes `9,884` / `1,056`; no loose duplicates found. | `BAR.EPF` header reports `12` frames of `138x16`; `BAR.PAL` begins with `DLPalette`. |
| `COMMA.EPF` / `COMMA.PAL` | `bint0.dat` entries `55`/`56`, offsets `10,271,153` / `10,271,309`, sizes `156` / `1,056`; no loose duplicates found. | `COMMA.EPF` header reports `3` frames of `4x5`; `COMMA.PAL` begins with `DLPalette`. |
| `ITEMINV.PAL` | `bint2.dat`, entry index `9`, offset `7,280,427`, size `1,056`; no loose duplicate found. | Shared inventory/status palette; header begins with `DLPalette`. |
| `NPAL5.PAL` / `NPAL7.PAL` | `bint2.dat` entries `47`/`49`, offsets `9,158,767` / `9,160,879`, sizes `1,056` each; no loose duplicates found. | Shared legacy palette family; both headers begin with `DLPalette`. |
| `USERSTAT.EPD`, `NATION.EPD`, `TOTEM.EPD`, `CLASS.EPD`, `BAR.EPD` | No exact DAT entry and no loose exact file found in the current audited package. The names remain UTF-16 executable literals in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`. | Runtime operands and consumers are proven by IDA, but the legacy `.EPD` image payloads remain distribution/version blockers. |

This resolves the current-package location for the EPF compact/newer assets and shared palettes, but it does not make the `NPAL*` palettes status-pane-private. Their xref fanout still proves shared-resource status.

## Resource Ownership

These resources should remain with the local status panel source area when direct xrefs support that owner. `COMMA` is directly tied to `UserStatusPane2`; `BAR.EPF` / `BAR.PAL` are status-meter-like and do have compact status-paint xrefs, but they also route through separate helper families and need another pass before treating them as exclusively owned by `UserStatusPane2`. Broader reuse should be documented in separate resource pages if later xrefs show other owners.

## Pane Variant Matrix

| Pane variant | Layout path | Direct resource role |
| --- | --- | --- |
| [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) | Newer layout; constructed with [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md) from `InitializeMainUiGraph` | Loads `9X11FONT.BIN`, paints the `USERSTAT.EPF` / `USERSTAT.EPD` status frame family, draws nation/totem/class icons through `NATION.EPD`, `TOTEM.EPD`, and `CLASS.EPD`, and uses `ITEMINV.PAL`, `NPAL7.PAL`, and `NPAL5.PAL` in the status/icon paths. |
| [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md) | Compact companion pane in the newer layout | Uses the shared `9X11FONT.BIN` glyph table, draws compact meter values, and has direct `COMMA.EPF` / `COMMA.PAL` xrefs for grouped numeric separators. Current xrefs also place `BAR.EPF` / `BAR.PAL` in the compact paint method, but the same strings are shared with helper families, so exclusive ownership remains open. |
| [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) | Legacy layout; constructed instead of the newer pair | Loads `9X11FONT.BIN`, paints the legacy `USERSTAT.EPD` panel, draws the same nation/totem/class icon resources, and shares the legacy `NPAL7.PAL` / `NPAL5.PAL` palette paths with the newer status pane. |

## Frame And Layout Semantics Checked

2026-06-16 filtered decompilation on IDA session `b001_mappane_0001AW_20260616` resolved several source-visible frame roles without proving final visual art:

- `UserStatusPane::OnPaint` loads `USERSTAT.EPF` frame `0` in the [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) branch and loads `USERSTAT.EPD` frame `0` with `NPAL7.PAL` in the legacy branch.
- The newer and old status panes use `NATION.EPD` indexed by the nation field, `TOTEM.EPD` indexed by the spirit/totem field, and `CLASS.EPD` with the observed class mapping `0 -> 4` and otherwise `class - 1`; `CLASS.EPD` renders with `NPAL5.PAL`.
- `BAR.EPD` is loaded as frame `2` plus frames `0` and `1` for the two newer/old status-meter fills; the draw math uses `MulDiv` against current/max values before calling the shared render callback.
- `UserStatusPane2::OnPaint` loads `COMMA.EPF` frame `0`, then uses `BAR.EPF` frame triples `0/1/2`, `3/4/5`, and `6/7/8` in source rectangles `(3,0)-(123,16)`, `(3,19)-(123,35)`, and `(3,57)-(123,73)`. `COMMA.PAL` is drawn when the compact numeric formatting inserts grouping separators.

## Rebuild Packaging Notes

- Rebuild handling is `resource-derived`: the final project should package or reference the named DAT assets, while the pane code should preserve the loader calls and resource-key strings.
- `9X11FONT.BIN` is a shared status-pane glyph payload rather than a C++ table owned by one pane class.
- `USERSTAT`, `NATION`, `TOTEM`, `CLASS`, and `COMMA` are documented enough to keep their status-panel consumers reconstructable, but the page does not yet prove visual frame identity, legacy `.EPD` package source, or palette slot ordering for every asset.
- `BAR.EPD` is directly in the legacy/new status paint set. `BAR.EPF` / `BAR.PAL` are now confirmed in the compact `UserStatusPane2` paint method as well as helper families at `0x0041ba40-0x0041bdce` and `0x0056ce50`; keep the shared-resource distinction until a helper page ties the pair to a specific source owner.

## Open Questions

- Visual identities and palette-slot ordering for the legacy `.EPD` assets, unused `COMMA.EPF` frames, and the remaining `BAR.EPF` frames not tied to compact status rows by this pass.
- Whether `BAR.EPF` / `BAR.PAL` are exclusively compact-status assets, shared meter helper assets, or a reusable UI bar resource consumed outside status panes.
- Locate the current-package or older-distribution payload source for `USERSTAT.EPD`, `NATION.EPD`, `TOTEM.EPD`, `CLASS.EPD`, and `BAR.EPD`.
- Final shared palette/resource owner pages for `NPAL7.PAL`, `NPAL5.PAL`, `ITEMINV.PAL`, and helper-routed `BAR.*`; this page proves status-pane consumption, not exclusive ownership.

## IDA MCP Evidence

- UTF-16 `9X11FONT.BIN` at `0x0061682c` is referenced from constructors including `0x005b83b0-0x005b8526`, `0x005bab00-0x005babf7`, and `0x005bda40-0x005bdb63`, matching the three status-pane families.
- UTF-16 `USERSTAT.EPF` at `0x00630edc` is referenced from `0x005b8c70-0x005b9d6a`; UTF-16 `USERSTAT.EPD` at `0x00630ef8` is referenced from both `0x005b8c70-0x005b9d6a` and `0x005be520-0x005bf10d`.
- UTF-16 status icon resources are verified at `0x00630f14` (`NATION.EPD`), `0x00630f2c` (`TOTEM.EPD`), `0x00630f40` (`CLASS.EPD`), `0x00630f5c` (`BAR.EPD`), `0x006152ec` (`NPAL7.PAL`), `0x00610fd0` (`NPAL5.PAL`), and `0x0061c964` (`ITEMINV.PAL`), with xrefs into `0x005b8c70-0x005b9d6a` and/or `0x005be520-0x005bf10d`.
- ASCII `COMMA.EPF` at `0x006247f0` and `COMMA.PAL` at `0x006248cc` are referenced from `0x005baf80-0x005bbe15`, directly supporting the `UserStatusPane2` compact-number path.
- UTF-16 `BAR.EPF` at `0x0060db00` and `BAR.PAL` at `0x0060db10` are referenced by `0x0041ba40-0x0041bdce`; this helper needs ownership tracing before the `BAR` pair is treated as uniquely part of `UserStatusPane2`.
- 2026-06-14 live IDA MCP session `a001_goal2_class_batch` reconfirmed key function bounds: `UserStatusPane` constructor `sub_5B83B0` size `0x176` / 374 bytes, `UserStatusPane` paint `sub_5B8C70` size `0x10fa` / 4346 bytes, `UserStatusPane2` constructor `sub_5BAB00` size `0xf7` / 247 bytes, compact paint `sub_5BAF80` size `0xe95` / 3733 bytes, `OldUserStatusPane` paint `sub_5BE520` size `0xbed` / 3053 bytes, and BAR helper `sub_41BA40` size `0x38e` / 910 bytes (Verified with `int_convert.py`).
- The same refresh reconfirmed `9X11FONT.BIN` at `0x0061682c` with 9 xrefs, including status constructors `0x005b8438`, `0x005bab65`, and `0x005bdaa5`.
- Current xrefs for the status literal tail show `USERSTAT.EPF` at `0x005b8cd0`; `USERSTAT.EPD` at `0x005b9126` and `0x005be576`; `NATION.EPD` at `0x005b9233` and `0x005be65a`; `TOTEM.EPD` at `0x005b93f0` and `0x005be81a`; `CLASS.EPD` at `0x005b950b` and `0x005be92a`; and `BAR.EPD` at eight newer/old status paint sites.
- Current palette/string xrefs show `NPAL7.PAL` at 10 refs including status sites `0x005b9132`, `0x005b926f`, `0x005b9425`, `0x005be582`, `0x005be69a`, and `0x005be84d`; `NPAL5.PAL` at status class-icon sites `0x005b9519` and `0x005be938`; and `ITEMINV.PAL` with 12 refs including `0x005b8cdc`.
- Current `COMMA` xrefs show `COMMA.EPF` with 3 refs including compact status paint `0x005bb006`, and `COMMA.PAL` with 7 refs including compact paint refs `0x005bb2fb`, `0x005bb67b`, `0x005bba10`, and `0x005bbc1f`.
- Current `BAR.EPF` and `BAR.PAL` xrefs show 21 refs each across `sub_41BA40`, `sub_56CE50`, and compact status paint `sub_5BAF80`; compact paint refs include `BAR.EPF` at `0x005bb032`, `0x005bb047`, `0x005bb05c`, `0x005bb3b3`, `0x005bb3c8`, `0x005bb3dd`, `0x005bb736`, `0x005bb74b`, and `0x005bb760`, and `BAR.PAL` at `0x005bb0cc`, `0x005bb144`, `0x005bb169`, `0x005bb44d`, `0x005bb4c5`, `0x005bb4ea`, `0x005bb819`, `0x005bb842`, and `0x005bb867`.
- 2026-06-14 `get_bytes` using MCP `regions` decoded the UTF-16 literal clusters at `0x00630edc` (`USERSTAT.EPF`, `USERSTAT.EPD`, `NATION.EPD`, `TOTEM.EPD`, `CLASS.EPD`, `BAR.EPD`), `0x006247f0` (`COMMA.EPF` and `COMMA.PAL` among adjacent UI strings), `0x0060db00` (`BAR.EPF`, `BAR.PAL`), and `0x0061682c` (`9X11FONT.BIN`). This closes the prior stale-session caveat for literal identity.
- 2026-06-14 A003 resume refresh on `a001_goal2_class_batch` reconfirmed the direct status-pane xrefs and shared fanout: `9X11FONT.BIN` has 9 refs including all three status constructors at `0x005b8438`, `0x005bab65`, and `0x005bdaa5`; `USERSTAT.EPF` has one direct ref at `0x005b8cd0`; `USERSTAT.EPD`, `NATION.EPD`, `TOTEM.EPD`, and `CLASS.EPD` each have newer and old-status paint refs; `BAR.EPD` has eight newer/old status paint refs; `COMMA.EPF` has three refs including compact paint `0x005bb006`; `COMMA.PAL` has seven refs including compact paint refs `0x005bb2fb`, `0x005bb67b`, `0x005bba10`, and `0x005bbc1f`.
- The same A003 refresh decoded adjacent resource/name context: the status tail includes `USERSTAT.*`, `NATION.EPD`, `TOTEM.EPD`, `CLASS.EPD`, `%3u`, `BAR.EPD`, and a following `%04u/%04` format fragment; the `COMMA` cluster also includes `LOOKICON.EPF`, `STATBUTS.EPF`, nation/totem text names, and `Head`, confirming this page should not widen compact-status ownership beyond the documented `COMMA` refs.
- `analyze_function` in the same session reconfirmed the direct consumer sizes and roles: `sub_5B83B0`, `sub_5BAB00`, and `sub_5BDA40` are the three font-loading constructors; `sub_5B8C70`, `sub_5BAF80`, and `sub_5BE520` are the status paint paths; `sub_41BA40` and `sub_56CE50` remain separate `BAR.*` helper families, preserving the shared-resource caveat.
- 2026-06-16 A002 refresh on IDA session `b001_mappane_0001AW_20260616` reconfirmed the same consumer surface and xref counts: `9X11FONT.BIN` has 9 refs including all three status constructors; `USERSTAT.EPF` has one newer-paint ref; `USERSTAT.EPD`, `NATION.EPD`, `TOTEM.EPD`, and `CLASS.EPD` each have newer and old paint refs; `BAR.EPD` has 8 newer/old status refs; `COMMA.EPF` has 3 refs with compact status at `0x005bb006`; `COMMA.PAL` has 7 refs with compact status at `0x005bb2fb`, `0x005bb67b`, `0x005bba10`, and `0x005bbc1f`; and `BAR.EPF`/`BAR.PAL` still have 21 refs each across `sub_41BA40`, `sub_56CE50`, and compact status paint.
- The same 2026-06-16 pass checked filtered decompilation for `0x005b8c70`, `0x005baf80`, and `0x005be520`, resolving the source-visible frame indices and rectangles recorded above while leaving visual asset identity and helper ownership open.
- 2026-06-16 package audit found `9X11FONT.BIN`, `BAR.EPF`/`.PAL`, `COMMA.EPF`/`.PAL`, `USERSTAT.EPF`, `ITEMINV.PAL`, `NPAL5.PAL`, and `NPAL7.PAL` in the current DAT archives; no exact DAT or loose files were found for the legacy `.EPD` status/icon/bar payloads.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `90` | The page now records pane-variant routing, resource-derived packaging, exact resource literal addresses, current xref counts/sites, current function summaries, byte-decoded literal clusters with neighboring-context exclusions, DAT package entries/header evidence for the current EPF/PAL/BIN payloads, negative current-package findings for legacy `.EPD` payloads, source-visible frame indices, and the refined shared `BAR.EPF` / `BAR.PAL` distinction. Completion remains capped by visual frame validation, missing legacy payloads, palette ownership, and helper-source ownership for BAR resources. |
| Confidence `92` | Current IDA bytes, filtered xrefs, decompilation, package parsing, executable raw-name scans, and owner docs agree on the status-pane resource set and consumers. Confidence remains below final audit because shared palette/BAR ownership and legacy `.EPD` payload provenance are not fully resolved. |

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
- 2026-06-07 A002 pane/resource matrix:
  - Before: the page listed the resources and basic owners but did not spell out the three pane-variant routing or the rebuild packaging boundary.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:86`, added the pane variant matrix, resource-derived packaging notes, explicit open questions, and a current-session IDA-availability caveat.
  - Summary and evidence: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md), [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md), [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md), [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md), [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md), [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md), and [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md) agree on the three status-pane variants, shared glyph table, status/icon resources, `COMMA` compact-number ownership, and unresolved helper-routed `BAR.EPF` / `BAR.PAL` ownership.
- 2026-06-14 C001 live IDA refresh: Raised completion/confidence from `78/86` to `86/88`.
  - Before: the page still carried a stale note that the previous pass could not claim a fresh IDA literal/xref pass, and `BAR.EPF` / `BAR.PAL` wording under-reported direct compact-paint xrefs.
  - After: the page records current function bounds, literal xref counts/sites, byte-decoded resource clusters, a refined shared-BAR ownership caveat, and a score rationale.
  - Evidence: live IDA MCP `idb_list`, `lookup_funcs`, `xrefs_to`, and `get_bytes` on 2026-06-14 plus `int_convert.py` size conversions.
- 2026-06-14 A003 resume refresh:
  - Raised completion/confidence from `86/88` to `88/90`.
  - Added current filtered xref counts, byte cluster decode confirmation with neighboring-context exclusions, and function summaries preserving the direct status-pane versus shared-BAR helper split.
  - Evidence: live IDA MCP `get_bytes`, `xrefs_to`, and `analyze_function` on `a001_goal2_class_batch`; frame indices, layout rectangles, DAT grouping, and helper-source ownership for `BAR.*` remain below final-audit quality.
- 2026-06-16 A002 resource-provenance refresh:
  - Raised completion/confidence from `88/90` to `90/92`.
  - Added current DAT entry and payload-header evidence for the packaged `9X11FONT.BIN`, `USERSTAT.EPF`, `BAR.EPF`/`.PAL`, `COMMA.EPF`/`.PAL`, `ITEMINV.PAL`, `NPAL5.PAL`, and `NPAL7.PAL` resources; recorded a current all-resource loose-file scan and negative DAT findings for the legacy `.EPD` status/icon/bar payloads; and documented source-visible frame-index/rectangle evidence from filtered decompilation.
  - Evidence checked: IDA MCP `lookup_funcs`, `xrefs_to`, and `decompile` on `b001_mappane_0001AW_20260616`; fixed-table DAT parsing under `E:\2026\Resources\Read_Only\NexusTK\Data`; exact loose-name search under `E:\2026\Resources`; and UTF-16 executable raw-name scans of `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`.
