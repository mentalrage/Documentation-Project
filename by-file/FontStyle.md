*** UID:0000JI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FontStyle

## Status

- Confidence: very strong for behavior, ranges, layout, compiler/source distinctions, ownership, and the required CPP/H route; high for the inferred original standalone file spelling.
- Reconstructed module: `ui/controls/FontStyle.cpp` with required sibling `ui/controls/FontStyle.h`.
- Source-placement decision: standalone reusable UI-control support. StaticText, HelpPane, MiniMap, and NewMail are consumers, not owners.
- Projected reconstruction path: `NexusTK/ui/controls/FontStyle.cpp`
- Exact source-bearing code ranges: `0x004536e0-0x00453732`, `0x00499f10-0x00499fda`; compiler/vector support at `0x0049ac60-0x0049ad74`

## File Role

`FontStyle` is a small reusable text-style descriptor used by static text, HelpPane text rendering, MiniMap label setup, and NewMail label setup. The object is 0x20 bytes in the recovered layout: a short scalar style header followed by a vector-style rule collection for 16-byte `FontStyleRule` records.

The accepted generated route is `NexusTK/ui/controls/FontStyle.cpp`. That route is stronger than MiniMap, NewMail, or HelpPane ownership because the same style descriptor is constructed/configured in multiple features and consumed by shared text-rendering controls.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:00005C][FontStyle](by-class/FontStyle.md) | declaration shell plus children | Emits `FontStyleRule`, `FontStyle`, and the `[[CHILDREN]]` insertion point for exact method bodies. |
| [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md) | data layout | Documents the 0x20-byte object layout plus 16-byte rule record layout; emits no source; UID00005C H is the sole declaration owner. |
| implicit `FontStyle` destruction | [UID:0000XM][0x004536e0-0x00453732.FontStyleImplicitDestructor](by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md) | Compiler-emitted destruction of `std::vector<FontStyleRule>`; no authored destructor or emitted source body. |
| `FontStyle::FontStyle` | `0x00499f10-0x00499f51` | Initializes `m_enabled`, `m_parentOpacity`, `m_textOpacity`, foreground/background scalar defaults, and empty vector pointers. |
| `FontStyle::GetRule` | `0x00499f60-0x00499f85` | Void bounded copy helper; copies one 16-byte rule record to a caller buffer when the requested index is in range. |
| `FontStyle::Configure` | `0x00499f90-0x00499fda` | Appends one `FontStyleRule { m_textColor, m_secondaryColor, m_effect, m_alignment }` record, using `0x0049ac60` only as compiler/vector growth support. |
| [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md) | `0x0049ac60-0x0049ad74` | Compiler/template-style vector insert/growth helper; do not treat as a separate handwritten project method. |

## Evidence Notes

- IDA MCP confirms `0x004536e0`, `0x00499f10`, `0x00499f60`, and `0x00499f90` as real functions with compact source-shaped bodies.
- 2026-05-26 IDA MCP recheck confirms `0x0049ac60` has one direct caller, `0x00499fcf` inside `FontStyle::Configure`, and decompiles as allocator/memmove-backed growth for 16-byte vector entries.
- Constructor callers include [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md), [UID:000096][NewMailDialog](by-class/NewMailDialog.md), and [UID:000063][HelpPane](by-class/HelpPane.md).
- The bounded rule lookup has two direct callers inside [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md)'s draw path, at `0x004c6723` and `0x004c67b3`.
- Configure callers include `MiniMapDialog` and `NewMailDialog` constructor paths and additional minimap-local style setup paths.
- `HelpPane::HelpPane` constructs an embedded style record at object offset `+0xfc`, then copies a caller-provided `FontStyle`-compatible record into it.
- `MiniMapDialog::MiniMapDialog` builds one local style object, configures it as `Configure(0x80, 6, 1, 0)`, and passes it to several `StaticTextControlPane2` labels.
- `NewMailDialog::NewMailDialog` uses a similar local style object for the "Keep a copy" static label in the EPF mail-skin path. Earlier source-output views hide this behind `TextStyle labelStyle = BuildDialogTextStyle(...)`, but IDA shows raw calls to `0x00499f10` and `0x00499f90`.
- HelpPane and StaticText2 consumers now support source-facing rule names: `m_textColor`, `m_secondaryColor`, `m_effect`, and `m_alignment`. The old count-returning `GetRule` interpretation is rejected because known callers ignore the return register and only use the copied rule.

## Accepted Whole-File Reconstruction

The complete modeled inventory is five bodies: three source-authored out-of-line methods and two compiler products. No file-owned global, static, string, table, vtable, RTTI object, resource, or import was found. Six scalar accessors are header-inline source and require no standalone binary entry. Copy construction, assignment, and destruction use normal implicit `std::vector` special-member lowering rather than authored helper bodies.

| Exact range | Size | Body SHA256 | Final source disposition |
| --- | ---: | --- | --- |
| `[0x004536e0,0x00453732)` | 82 | `FBCB522B63D7C1AD48E3941E428AF7099395E16D73C1425896BD613950A33F04` | Compiler-emitted implicit vector destructor; UID0000XM is non-reconstructable and non-emitting. |
| `[0x00453732,0x00453740)` | 14 | `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356` | Separate all-`0xcc` linker alignment after UID0000XM; not part of the destructor or authored source. |
| `[0x00499f10,0x00499f51)` | 65 | `E2C92A3449ED6693F5F2F7933CA215DAE05FDE09FE4C635EE2A9C2FC449525A7` | Authored `FontStyle::FontStyle()`. |
| `[0x00499f60,0x00499f85)` | 37 | `A7C6EA02E0464241B69BADAC2417EE6DE85349D158FD8F045A5DC0D15B4D73EB` | Authored void bounded `FontStyle::GetRule`. |
| `[0x00499f90,0x00499fda)` | 74 | `7C90F35C90A82A8A5E379E68787F2F9CBDF5720FA1F3E77F926FC383325576DB` | Authored `FontStyle::Configure` using `m_rules.push_back(rule)`. |
| `[0x0049ac60,0x0049ad74)` | 276 | `DB6C0E4F6F2DAA5F7EE94BBB589E1433A5BDDFD8ACBC2C80F70840F85EAFA7D2` | Compiler `std::vector<FontStyleRule>` growth; UID00011W remains ignored/non-emitting. |

The authored ranges remain grouped in physical order under [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md) at emitter position 10. Their intervening `0xcc` spans are alignment, not owned source. UID0000XM ends exclusively at `0x00453732`; the fourteen bytes through `0x00453740` are separate alignment. The superseded 83-byte `[0x004536e0,0x00453733)` aggregate entry incorrectly absorbed the first alignment byte and is retained only as this historical correction. The discontiguous destructor and growth bodies are compiler products caused by the header declaration and vector member; their placement does not imply MiniMap or feature ownership.

`FontStyle.h` owns `FontStyleRule`, `FontStyle`, six inline accessors, three out-of-line method declarations, and implicit special members. `FontStyle.cpp` includes that header and receives the three authored definitions through the class child route. Natural 32-bit MSVC alignment yields `sizeof(FontStyleRule)==0x10` and `sizeof(FontStyle)==0x20`; no explicit padding fields belong in developer source.

Cross-feature evidence is exact: constructor and Configure have seven direct call sites across MiniMap, NewMail, and HelpPane setup; GetRule has two HelpPane draw-path calls; cleanup has ten direct/EH xrefs across MiniMap, NewMail, StaticText2, and HelpPane; vector growth has one call at `0x00499fcf` from Configure. This fanout requires a shared complete header and rejects a feature-local or headerless source shape.

Generated closure requires `FontStyle.cpp` to contain only the header include followed by constructor, GetRule, and Configure in physical order, and `FontStyle.h` to contain the complete natural declarations. `StaticTextControlPane.cpp` and `HelpPanes.cpp` must include `FontStyle.h` before their first by-value use. An explicit destructor, layout comment emitter, declaration shell in CPP, compiler-growth body, stub, or empty-emitter marker is incorrect.

## Ownership Decision

Keep this as reusable UI text-style support. It should not be owned by `MiniMapDialog`, `NewMailDialog`, or `HelpPane` even though those are important callers/consumers.

The accepted source shape is standalone `ui/controls/FontStyle.cpp` plus `FontStyle.h`. Address adjacency permits a weaker StaticText fold, but the compact authored cluster, current route, and independent by-value consumers make the standalone module the highest-probability original shape. Exact original project-file spelling remains a confidence cap, not an implementation blocker.

Rejected ownership/source alternatives:

- `MiniMap`: consumer/local style setup only.
- `MailDialogs` / `NewMailDialog`: consumer/local style setup only.
- `HelpPanes`: direct `GetRule` consumer but not full constructor/configure owner.
- Container-only source: rejected for constructor/GetRule/Configure/destructor shape; accepted only for `0x0049ac60` vector growth support.

## Current Caveats

- Exact original lexical spellings and Visual Studio project-file entry are stripped. The selected names are the strongest corpus-consistent human source names and must not regress to `sub_`, `_DWORD`, or generic reverse-engineering labels.
- The high three bytes after rule `m_effect` are natural alignment before dword `m_alignment` at `+0x0c`; they are not an explicit source field and `m_effect` must remain byte-sized.
- `0x0049ac60` is called only by `FontStyle::Configure` and remains compiler/template support represented by `m_rules.push_back(rule)`.

## Cross-References

- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md)
- [UID:0000XM][0x004536e0-0x00453732.FontStyleImplicitDestructor](by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md)
- [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md)
- [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md)
- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)

## Changes

- 2026-08-17 B006 accepted UID0000JI whole-file callback:
  - Raised `86/89 -> 94/94` while retaining the standalone `NexusTK/ui/controls/` route and `CANONICAL_OWNER:FILE`.
  - Reconciled all five modeled bodies, six inline accessors, two source types, compiler products, callers/xrefs, exact ranges/hashes, alignment gaps, source order, and negative inventory.
  - Made `FontStyle.cpp` plus required `FontStyle.h` authoritative, rejected feature-local/headerless alternatives, removed authored-destructor and explicit-padding source assumptions, and recorded generated consumer include requirements.
  - Renamed the UID0000XM link to `FontStyleImplicitDestructor`; earlier `ClearRules`, empty-destructor, CPP-only declaration, and header-uncertain statements below are retained only as historical development of the reconstruction.

- 2026-06-21 B012 FontStyle source-quality incorporation:
  - Kept: `86/89`, route `NexusTK/ui/controls/FontStyle.cpp`, reusable `FontStyle` file ownership, and non-emitting vector-growth handling.
  - Changed: source-facing field/rule names now match the B012 recommendation (`m_parentOpacity`, `m_textOpacity`, `m_foregroundColor`, `m_backgroundColor`, `m_rules`, `m_textColor`, `m_secondaryColor`, `m_effect`, and `m_alignment`), while MiniMap, Mail, HelpPane, and StaticText remain consumers rather than owners.
  - Summary/evidence: B012 revalidated that the constructor/configure/GetRule fan-out crosses MiniMap, Mail, HelpPane, and StaticText, so `FontStyle.cpp` remains the first source-bearing emission route unless later recovered source proves a different split.
- 2026-06-20 B006 FontStyle source-quality implementation:
  - Before: `84/88`, valid generated path but empty-marker output only.
  - Changed to: `86/89`, current route `NexusTK/ui/controls/FontStyle.cpp`, declaration-shell requirement, accepted `FontStyleRule` field names, destructor-like cleanup policy, and rejected MiniMap/NewMail/HelpPane/container-only ownership alternatives.
  - Summary/evidence: accepted B006 report revalidated constructor/configure/GetRule fan-out, HelpPane/StaticText2 rule consumers, and vector-growth non-emission. Generated file should now be assembled from [UID:00005C][FontStyle](by-class/FontStyle.md), [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md), [UID:0000XM][0x004536e0-0x00453732.FontStyleImplicitDestructor](by-memory/0x004536e0-0x00453732.FontStyleImplicitDestructor.md), and [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md).
- 2026-06-05: A004 raised the file page to `84/88`, added the live `0x00499f60` bounded rule lookup, updated caller evidence for HelpPane text rendering, and kept final C++ blank pending original source-placement and rule-field naming proof.
- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/controls/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree both place `FontStyle.cpp` with UI controls.
  - After: set the validator path to `NexusTK/ui/controls/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `FontStyle.cpp` under `ui/controls`, and live IDA MCP lookup on 2026-06-05 confirms the constructor anchor at `0x00499f10` as a real function of size `0x41`.
- 2026-05-30: Scored the file page from 0/0 to 76/84 and linked the `FontStyle::ClearRules` row to its detailed by-memory page. Evidence: current IDA MCP recheck confirms `ClearRules` bounds/callers/callees, while existing docs already cover the constructor/configure functions, 0x20-byte layout, rule-vector growth helper, and cross-feature consumers.
