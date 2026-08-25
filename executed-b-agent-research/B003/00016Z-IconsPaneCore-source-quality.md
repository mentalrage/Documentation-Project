** TARGET-REPORT-UID:00016Z **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Source-Quality Research: 00016Z IconsPaneCore

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00016Z] `IconsPaneCore` as a reconstructable `IconsPane` aggregate owned by [UID:00006B] `IconsPane` and emitted through [UID:00006B], with source placement in [UID:0000JZ] `IconsPane.cpp`.
- Do not emit a full aggregate C++ body. The aggregate is a physical/index range; exact child method pages should emit source bodies. If the validator requires non-empty C++ for an eligible emitter, use a marker-only comment:

```cpp
// IconsPaneCore is an aggregate index; exact child pages emit the IconsPane method bodies.
```

- Required documentation correction: the current child list is not exact. The range `0x004cf74b-0x004cf7d0` sits between `IconsPane::OnMouseEvent` and `IconsPane::HitTestIcon` and contains embedded switch tables plus a small unreferenced icon-rectangle helper. It should be split/documented instead of being left implicit.
- Recommended target score after the gap and raw-helper findings are incorporated: `86/88` without new child pages, or `88/89` after the `0x004cf74b-0x004cf7d0` gap is split into exact children/padding. Current `85/86` should not be raised while the target still says "exact child coverage" but omits that span.
- Adjacent [UID:00022Q] `0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody` remains retained executable duplicate/action-dispatch evidence. Direct PE scans found no VA pointer, RVA pointer, or direct branch to `0x004cf8e0`; do not promote it to a required callable helper.
- Report-only status: no by-* docs, generated files, IDA database, or coverage files were edited.

## Target

- Target UID: `00016Z`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004cf1f0-0x004cf8d5.IconsPaneCore.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B003\research\00016Z-IconsPaneCore-source-quality.md`
- Current target score: `85/86`
- Current owner/emitter: `CANONICAL_OWNER:00006B`, `EMITTER_UIDS:00006B`
- Current C++: blank; generated output shows an empty emitter marker for this UID in `auto-generated/NexusTK/ui/panels/IconsPane.cpp`.

## Evidence Checked

Required and support docs:

- `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`
- Exact child pages [UID:0002SW] through [UID:0002T4]:
  `IconsPaneConstructor`, `IconsPaneCleanupHelper`, `IconsPaneIsShowingAllIcons`, `IconsPaneShowAllIcons`, `IconsPaneShowReducedIcons`, `IconsPaneOnPaint`, `IconsPaneOnMouseEvent`, `IconsPaneHitTestIcon`, and `IconsPaneSetIconHighlight`
- [UID:00022Q] `by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md`
- [UID:000170] `by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md`
- [UID:00034T] `IconsPaneDestructorAdjustorThunks`
- [UID:00034V] `IconsPaneScalarDeletingDestructor`
- [UID:00006B] `by-class/IconsPane.md`
- [UID:0000JZ] `by-file/IconsPane.md`
- [UID:0000EB] `by-class/TabPane.md`
- [UID:0000OF] `by-file/TabPane.md`
- [UID:0000R6] `by-global/g_pIconsPane.md`
- [UID:0002XU] `by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md`
- [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- [UID:0001RD] `by-resource/iconspane-icon-resources.md`
- [UID:0003BN] `by-memory/0x0061b444-0x0061b4cc.IconsPaneVtableData.md`
- [UID:0001KO] `0x005a4b60-0x005a5791.SayModeHelpers`
- [UID:00030A] `0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots`
- [UID:0002RX] `0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode`
- [UID:0000TD] `OpenQuitPrompt_5A94B0`
- `by-memory/-coverage-report.md` as read-only evidence
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/ui/panels/IconsPane.cpp`
- `auto-generated/NexusTK/ui/panels/TabPane.cpp`
- `project-level/-resolved.md`, `project-level/-auto-completion-stats.md`

Direct binary evidence:

- Read-only binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Direct PE section parsing plus Capstone x86 disassembly.
- Direct scans for absolute VA dwords, RVA dwords, and direct `E8`/`E9`/short/near conditional branch encodings.
- No live IDA MCP tool was exposed in this session; existing IDA MCP facts in the docs were treated as documentation evidence and rechecked with direct PE bytes where possible.

## Boundary And Coverage Recheck

The aggregate range is correctly bounded as `0x004cf1f0-0x004cf8d5`, but the child coverage currently omits one non-padding span.

Confirmed aggregate layout:

| Range | Disposition | Recommendation |
| --- | --- | --- |
| `0x004cf1f0-0x004cf25d` | `IconsPane::IconsPane()` | Existing [UID:0002SW], owner [UID:00006B]. |
| `0x004cf25d-0x004cf260` | `0xcc` padding | Covered by child docs/aggregate notes; no source. |
| `0x004cf260-0x004cf289` | cleanup/destructor helper | Existing [UID:0002SX], owner [UID:00006B]. |
| `0x004cf289-0x004cf290` | `0xcc` padding | Ignored/alignment. |
| `0x004cf290-0x004cf297` | `IsShowingAllIcons` | Existing [UID:0002SY]. |
| `0x004cf297-0x004cf2a0` | `0xcc` padding | Ignored/alignment. |
| `0x004cf2a0-0x004cf2c6` | `ShowAllIcons` | Existing [UID:0002SZ]. |
| `0x004cf2c6-0x004cf2d0` | `0xcc` padding | Ignored/alignment. |
| `0x004cf2d0-0x004cf2f6` | `ShowReducedIcons` | Existing [UID:0002T0]. |
| `0x004cf2f6-0x004cf300` | `0xcc` padding | Ignored/alignment. |
| `0x004cf300-0x004cf3d3` | `OnPaint` | Existing [UID:0002T1]. |
| `0x004cf3d3-0x004cf3e0` | `0xcc` padding | Ignored/alignment. |
| `0x004cf3e0-0x004cf74b` | `OnMouseEvent` function body | Existing [UID:0002T2]. |
| `0x004cf74b-0x004cf7a0` | `OnMouseEvent` switch data: event-mode table, tooltip-id table, click-action table | Missing exact child. Split as non-emitting switch/table data tied semantically to `OnMouseEvent`. |
| `0x004cf7a0-0x004cf7c9` | function-shaped no-xref helper that builds an icon rectangle for an index | Missing exact child. Split as retained raw `IconsPane.cpp` helper evidence, likely `BuildIconButtonRect` / `BuildIconRectForIndex`. |
| `0x004cf7c9-0x004cf7d0` | seven `0xcc` bytes | Add ignored padding row/doc note. |
| `0x004cf7d0-0x004cf862` | `HitTestIcon` | Existing [UID:0002T3]. |
| `0x004cf862-0x004cf870` | fourteen `0xcc` bytes | Already in `-ignored`. |
| `0x004cf870-0x004cf8d5` | `SetIconHighlight` | Existing [UID:0002T4]. |

Direct PE details for the missing gap:

- `0x004cf74b` is a single `90` byte before table data.
- `0x004cf74c-0x004cf760` is the five-entry event-mode jump table used by `jmp dword ptr [edx*4 + 0x4cf74c]` at `0x004cf426`.
  - Event `0` -> `0x004cf649`
  - Event `1` -> `0x004cf42d`
  - Event `2` -> `0x004cf735`
  - Event `3` -> `0x004cf692`
  - Event `4` -> `0x004cf47f`
- `0x004cf760-0x004cf780` is the eight-entry tooltip switch table used by `jmp dword ptr [eax*4 + 0x4cf760]` at `0x004cf4b9`.
  - Entries lead to tooltip constructors for localized ids `0xca..0xd1` / `202..209`.
- `0x004cf780-0x004cf7a0` is the eight-entry click-action switch table used by `jmp dword ptr [edx*4 + 0x4cf780]` at `0x004cf6d8`.
  - Entries lead to calls at `0x004cf6df`, `0x004cf6e6`, `0x004cf6ed`, `0x004cf6f6`, `0x004cf6fd`, `0x004cf704`, `0x004cf70b`, and `0x004cf712`.
- `0x004cf7a0-0x004cf7c9` disassembles as:

```asm
004cf7a0  push ebp
004cf7a1  mov  ebp, esp
004cf7a3  mov  eax, [ebp+8]      ; icon index
004cf7a6  mov  ecx, [ebp+0Ch]    ; out rect
004cf7a9  lea  eax, [eax+eax*4]
004cf7ac  shl  eax, 2            ; index * 20
004cf7af  mov  [ecx], eax        ; left
004cf7b1  add  eax, 13h
004cf7b4  mov  [ecx+4], 0        ; top
004cf7bb  mov  [ecx+0Ch], 0Eh    ; bottom
004cf7c2  mov  [ecx+8], eax      ; right
004cf7c5  pop  ebp
004cf7c6  retn 8
```

Direct branch/pointer scan results for important entries:

| Target | Direct branch/call hits | VA/RVA pointer hits | Source-quality conclusion |
| --- | --- | --- | --- |
| `0x004cf1f0` | `call 0x004f8706` | none | Constructor live from `InitializeMainUiGraph`. |
| `0x004cf290` | `call 0x0053da83` | none | Option UI query caller. |
| `0x004cf2a0` | `call 0x0053ded2` | none | Option UI apply caller. |
| `0x004cf2d0` | `call 0x0053dee0` | none | Option UI apply caller. |
| `0x004cf300` | no direct code call | one vtable dword at `0x0061b48c` | Paint is virtual. |
| `0x004cf3e0` | vtable dword at `0x0061b498`; internal branch artifact at `0x004cf3e6` is not an external caller | one vtable dword | Mouse handler is virtual. |
| `0x004cf7a0` | none | none | No evidence this helper is called/address-taken. |
| `0x004cf7d0` | calls at `0x004cf44e`, `0x004cf4a2`, `0x004cf667`, `0x004cf6b0` | none | Hit-test helper live only from `OnMouseEvent`. |
| `0x004cf870` | calls at `0x004cf473`, `0x004cf678`, `0x004cf686`, `0x004cf71b` | none | Highlight helper live only from `OnMouseEvent`. |
| `0x004cf8e0` | none | none | Raw action dispatcher remains unreferenced. |
| `0x004cf954` | no external code | one VA-like hit at `0x004cf902` | Local table operand inside raw dispatcher only. |
| `0x004cf980` | `call 0x004f812d` | none | TabPane constructor live from `InitializeMainUiGraph`. |
| `0x004cfda0` | jumps from adjustor thunks `0x004cfd72`, `0x004cfd7d`; vtable dword at `0x0061b448` | one vtable dword | IconsPane scalar deleting destructor wrapper. |

## Source-Quality Names And Fields

Recommended source-facing `IconsPane` class members:

| Binary offset | Recommended name | Evidence / caveat |
| --- | --- | --- |
| `this + 0xf8` | `m_showAllIcons` | Nonzero starts paint/hit-test at icon `0`; zero starts at icon `6`. Accessor returns this byte. |
| `this + 0xfc` | `m_selectedIconIndex` | Set to `-1` by constructor/release; used by paint and highlight invalidation. |
| `this + 0x100` | `m_isPressed` or `m_isIconPressed` | Pressed/highlight latch used to draw frame `index + 8`; current docs use `m_isPressed`. |

Recommended globals and field names:

| Raw/global | Recommended source-facing name | Confidence |
| --- | --- | --- |
| `dword_69B41C` / `0x0069b41c` | `g_pIconsPane` | Very high; IDA name and docs agree. |
| `dword_67A7C8` | `g_pConfig` | Very high; central config pointer doc. |
| `g_pConfig + 0x28de32` | `m_iconPaneReducedMode` preferred, or neutral `m_iconPaneDisplayMode` | High for semantics, medium for spelling. Stored `0` means full/all icons; stored `1` means reduced/two-icon mode. This is inverse of `IconsPane::m_showAllIcons`. |
| `dword_67A764 + 0x3f0` | `g_activeMapPane->m_inputLocked` or `g_activeMapPane->IsInputLocked()` | High for lock semantics, medium for final member spelling. Avoid standalone `g_isInputLocked`. |
| `dword_67A748` | `g_pCollectionData` | High; resolved-name docs and caller behavior agree. |
| `dword_67A744` | `g_pEPFLib` | High; resource draw path. |
| `dword_67A750` | `g_pLanguageMan` | High; tooltip localized ids. |
| `byte_66DA97` | `g_useEpfAssets` | High as broad mode flag; raw action helper consumers use the documented alias. |

Recommended local/helper names:

| Address | Recommended name | Confidence / reason |
| --- | --- | --- |
| `0x004cf7a0` | `IconsPane_BuildIconRectForIndexRaw` for IDA/docs; source-facing if live would be `BuildIconButtonRect` or `BuildIconRectForIndex` | Medium. Exact behavior is clear; no caller/address-taken route found. |
| `0x004cf8e0` | `IconsPaneActionDispatchRawBody` / `DispatchIconActionRawNoXref` | High for behavior, medium for original source reason. No route found. |
| `0x005a4db0` | `SwitchGeneralPurposePanelMode2WithClickSound` | High behavior confidence; calls `sub_4B8650(generalPurposePanel, 2, 0)` and timed UI request. |
| `0x005a4e40` | `SwitchGeneralPurposePanelMode3WithClickSound` | High behavior confidence; same pattern with mode `3`. |
| `0x005a4f70` | `SendOpcode2DAndStoreExtra` | High; sends opcode `0x2d`, subtype `0`, stores argument to `0x0069bf6c/70` based on `g_useEpfAssets`. |
| `0x005a5010` | `SyncNationEntriesOrDeferredState` / `ProcessDeferredSendState` | Medium-high; requests nation entries or forwards deferred state through `0x004aa050`. Do not force IconsPane ownership. |
| `0x005a50a0` | `EnsureNormalBulletinSession` | High; lazy `BulletinSession` initializer. |
| `0x005a5110` | `OpenInputPaneForCurrentSayMode` | High; exact child [UID:0002RX]. |
| `0x005a5340` | `SendOpcode43MinusOneRequest` | High; sends ten-byte opcode `0x43` request. |
| `0x005a5a80` | `OpenQuitPromptThunk` | High; five-byte thunk to `0x005a94b0`. |

Rejected action-helper names:

- Do not use icon-local labels like `OpenArrangeDialog`, `OpenOptionsDialog`, `OpenExchangeDialog`, `OpenMailDialog`, or `OpenQuestDialog` for the helper functions. The helper bodies are shared and behavior-oriented, not IconsPane-private UI labels.

## Raw Dispatch And TabPane Relationship

[UID:00022Q] is real executable code and should not be folded into padding:

- `0x004cf8e0-0x004cf952`: function-shaped body.
- `0x004cf952-0x004cf954`: `66 90` alignment.
- `0x004cf954-0x004cf974`: eight-entry jump table.
- `0x004cf974-0x004cf980`: `0xcc` padding before `TabPane`.

The body mirrors the live `OnMouseEvent` click switch and uses the same input-lock gate:

```asm
004cf8e3  mov eax, dword ptr [0x67a764]
004cf8e8  cmp byte ptr [eax+0x3f0], 0
004cf8f1  mov eax, [ebp+8]
004cf8f4  mov ecx, dword ptr [0x67a748]
004cf8ff  jmp dword ptr [eax*4 + 0x4cf954]
```

The direct PE scan found no loaded VA pointer, RVA pointer, or direct branch to `0x004cf8e0`. The only `0x004cf954` pointer-like hit is the local jump-table operand at `0x004cf902`. Best direction: keep [UID:00022Q] as retained raw old-HUD action evidence under `IconsPane.cpp` / file-level owner [UID:0000JZ], with formal C++ blank or marker-only until a route is found.

The following `TabPane` range starts cleanly at `0x004cf980`, with constructor caller `0x004f812d`. `TabPane` shares some action helper callees but has separate geometry, singleton, vtables, and source identity. Keep `IconsPane.cpp` and `TabPane.cpp` separate in docs/generation unless later source evidence proves a combined old-HUD controls file.

## Owner / Emitter / Source Placement

Recommended target metadata after doc corrections:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:00006B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006B
```

If the missing gap receives exact child pages and coverage entries:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:00006B
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006B
```

Source placement:

- Primary source route: [UID:0000JZ] `NexusTK/ui/panels/IconsPane.cpp`.
- Class owner: [UID:00006B] `IconsPane`.
- Do not move the core to `TabPane.cpp`: `TabPane` is adjacent and shares helper callees, but owns a different six-region action surface and separate singleton/vtables.
- Do not move action helper storage to `IconsPane`: `SendOpcode2DAndStoreExtra` state is documented under [UID:0000P1] `UserPane.cpp`; `IconsPane` is a consumer.
- Do not move resource ownership into `IconsPaneCore`: `ICONS.EPD`/`NPAL7.PAL` packaging remains in resource docs, while `IconsPane.cpp` owns frame-index behavior.

## C++ Readiness

Aggregate [UID:00016Z]:

- Formal C++ should be marker-only, not a full class/method implementation.
- Exact no-code proof:
  - The target is not a single source function.
  - It spans constructor, cleanup, accessors, mutators, paint, event handling, switch tables/raw helper bytes, hit-test, and highlight helper.
  - Exact child pages already own the source bodies and are individually emitted/marked.
  - A full aggregate block would duplicate child output and force unresolved helper names into one artificial function.

Child/source readiness:

- Constructor, accessors, show-mode mutators, hit-test, and highlight helper are first-draft C++ ready once common declarations are standardized.
- `OnPaint` and `OnMouseEvent` are behavior-ready, but final C++ should wait for shared render helper names, event structure names, tooltip constructor names, and action helper declarations.
- `0x004cf7a0` raw rectangle helper should not get source C++ unless a route is found; if documented as retained raw evidence, use blank or marker-only C++.
- [UID:00022Q] raw dispatcher should stay blank/marker-only until a caller/address-taken route is proven.

Recommended aggregate marker text:

```cpp
// IconsPaneCore is an aggregate index; exact child pages emit the IconsPane method bodies.
```

## Heuristic / Inference Reanalysis And Validation

Issue: "Exact child coverage" claim.

- Reanalysis: Direct PE bytes prove `0x004cf74b-0x004cf7d0` is not covered by existing child docs and is not all padding.
- Resolution: update target docs and coverage. Split into switch-table data, raw rect helper, and padding.

Issue: `g_pConfig + 0x28de32` source name.

- Evidence checked: constructor, show-mode setters, `g_pConfig` global page, OptionPane references.
- Best direction: `m_iconPaneReducedMode` is semantically clearest because stored `1` means reduced and stored `0` means full. `m_iconPaneDisplayMode` is safer if the project prefers neutral registry byte names.
- Uncertainty: exact original member spelling is not symbol-proven.

Issue: `0x004cf7a0` helper liveness.

- Evidence checked: direct branch scan, VA pointer scan, RVA pointer scan.
- Result: no route found.
- Best direction: retained raw helper candidate or dead/static helper emitted next to `OnMouseEvent`; document as `BuildIconRectForIndex` evidence, not a required source method.

Issue: [UID:00022Q] raw action dispatcher.

- Evidence checked: body disassembly, local table dwords, direct branch scan, VA/RVA pointer scan, comparison with `OnMouseEvent` and `TabPane`.
- Result: no route found; exact behavior duplicates live click-action switch.
- Best direction: retained duplicate old-HUD action evidence, not dead padding and not a live helper.

Issue: action helper names.

- Evidence checked: direct helper disassembly and support docs.
- Resolution: use behavior names listed above. Treat final UI-label names as open until a broader helper/UI-label pass resolves them.

Issue: source grouping with `TabPane`.

- Evidence checked: file/class docs, mixed tail, generated `IconsPane.cpp`/`TabPane.cpp`, direct PE call routes.
- Resolution: separate source files remain best. Shared helper callees and adjacency do not override singleton/vtable/resource/class ownership.

## Recommended Target Doc Changes

In `0x004cf1f0-0x004cf8d5.IconsPaneCore.md`:

1. Replace "exact child coverage" wording with "exact modeled method children plus one newly identified table/raw-helper gap".
2. Add a `0x004cf74b-0x004cf7d0` row in the covered range table:

```markdown
| `0x004cf74b-0x004cf7d0` | `IconsPane` / compiler-data gap | Embedded `OnMouseEvent` switch tables at `0x004cf74c-0x004cf7a0`, an unreferenced icon-rectangle helper at `0x004cf7a0-0x004cf7c9`, and `0x004cf7c9-0x004cf7d0` padding. Needs exact child split; do not treat as ordinary padding. |
```

3. Add a boundary note:

```markdown
Direct PE/Capstone recheck on 2026-06-19 found that the gap between `OnMouseEvent` and `HitTestIcon` is not empty: `0x004cf74c-0x004cf75f` is the event-mode switch table, `0x004cf760-0x004cf77f` is the tooltip-id switch table, `0x004cf780-0x004cf79f` is the click-action switch table, `0x004cf7a0-0x004cf7c9` builds `{left=index*20, top=0, right=index*20+19, bottom=14}`, and `0x004cf7c9-0x004cf7d0` is seven bytes of `0xcc` padding.
```

4. Update `Data Issues`:

```markdown
Current child pages cover the modeled method starts, but the `0x004cf74b-0x004cf7d0` table/raw-helper gap still needs an exact child split. [UID:00022Q] remains a separate retained raw duplicate action dispatcher with no entrypoint xrefs, no VA/RVA pointer hits, and no direct branch route.
```

5. Update aggregate C++ recommendation:

```markdown
Formal aggregate C++ should be marker-only. The aggregate is a physical/source index, not a source function; exact child pages own method source. Use `// IconsPaneCore is an aggregate index; exact child pages emit the IconsPane method bodies.` if the validator requires a non-empty eligible emitter.
```

6. Score recommendation:

```markdown
Completion/confidence should remain capped until `0x004cf74b-0x004cf7d0` is split. Recommended score after this text-only correction is `86/88`; after exact child split, `88/89`.
```

## Recommended Support Updates

`by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md`

- Expand the existing gap note into exact table boundaries:
  - event switch table `0x004cf74c-0x004cf760`
  - tooltip switch table `0x004cf760-0x004cf780`
  - click-action switch table `0x004cf780-0x004cf7a0`
  - raw rectangle helper `0x004cf7a0-0x004cf7c9`
  - padding `0x004cf7c9-0x004cf7d0`
- Add that the click-action table duplicates [UID:00022Q]'s action order.

`by-class/IconsPane.md`

- Add `0x004cf74b-0x004cf7d0` to the method/data inventory as "embedded OnMouseEvent tables and retained no-xref icon-rectangle helper".
- Change "core range exact method split" wording to include the missing gap.
- Add recommended config field direction: `g_pConfig->m_iconPaneReducedMode` preferred; `m_showAllIcons = !g_pConfig->m_iconPaneReducedMode`.

`by-file/IconsPane.md`

- Add the `0x004cf74b-0x004cf7d0` gap to proposed contents.
- Add that current `auto-generated/NexusTK/ui/panels/IconsPane.cpp` already contains an empty marker for [UID:00016Z] and most children, plus a real destructor draft from [UID:00034V].
- Keep [UID:00022Q] as retained raw no-route evidence under `IconsPane.cpp`.

`by-memory/-ignored.md`

- Add `0x004cf7c9-0x004cf7d0` as padding after the raw icon-rectangle helper and before `HitTestIcon`.
- Do not add `0x004cf74b-0x004cf7c9` to ignored; it is data/code evidence.

`by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md`

- No ownership change. Add the 2026-06-19 direct PE scan result: no VA pointer, no RVA pointer, no direct branch to `0x004cf8e0`; local `0x004cf954` table operand only.
- Keep behavior names for helper callees; do not convert them into final UI labels.

`by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md`

- No ownership change. Add only a cross-reference note that the preceding `0x004cf974-0x004cf980` padding remains a clean separator after the raw IconsPane dispatcher.

`by-resource/iconspane-icon-resources.md`

- Add no new resource owner. Optional note: the raw `0x004cf7a0` helper confirms the same `20x14` icon-slot geometry used by paint/hit-test/highlight.

`by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`

- Refine `+0x28de32` from "Icons-pane display mode byte" to:

```markdown
`+0x28de32` | IconsPane reduced-display-mode byte. `0` means full/all icons; `1` means reduced/two-icon strip. `IconsPane::m_showAllIcons` stores the inverse runtime bool.
```

`auto-generated/-ag-memory-coverage.md`

- After marker-only C++ is added to [UID:00016Z], the target row should change code from `no` to `yes` only if the validator treats marker comments as code. Otherwise leave it as `no` and teach the validator to accept aggregate markers.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. Recommended replacement for the existing aggregate row after text-only target update:

```markdown
    - [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md) 0x004cf1f0-0x004cf8d5 | class aggregate | IconsPaneCore : reconstructable : 86% : strong : B003 2026-06-19 source-quality pass keeps owner/emitter [UID:00006B][IconsPane](by-class/IconsPane.md), confirms constructor through highlight helper ownership under `IconsPane.cpp`, resolves `g_pConfig+0x28de32` as the persisted reduced-icon-mode byte inverse to `m_showAllIcons`, keeps action helpers on behavior names, revalidates [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md) as retained no-entry duplicate action evidence, and identifies the previously implicit `0x004cf74b-0x004cf7d0` gap as embedded `OnMouseEvent` switch tables plus a no-xref icon-rectangle helper requiring an exact child split; aggregate C++ should be marker-only because exact children emit method bodies.
```

Recommended updated child rows for stale existing child entries:

```markdown
      - [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md) 0x004cf290-0x004cf297 | accessor | IconsPaneIsShowingAllIcons : reconstructable : 86% : strong : Accessor returning `m_showAllIcons` at `this+0xf8`; live docs confirm exact 7-byte body, single OptionPane constructor caller at `0x0053da83`, and owner/emitter [UID:00006B][IconsPane](by-class/IconsPane.md).
      - [UID:0002SZ][0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons](by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md) 0x004cf2a0-0x004cf2c6 | method | IconsPaneShowAllIcons : reconstructable : 86% : strong : Full-mode mutator; writes `g_pConfig+0x28de32 = 0`, sets `m_showAllIcons`, invalidates pane bounds through virtual slot `+0x20`, and has single OptionPane apply caller `0x0053ded2`.
      - [UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md) 0x004cf2d0-0x004cf2f6 | method | IconsPaneShowReducedIcons : reconstructable : 86% : strong : Reduced-mode mutator; writes `g_pConfig+0x28de32 = 1`, clears `m_showAllIcons`, invalidates pane bounds through virtual slot `+0x20`, and has single OptionPane apply caller `0x0053dee0`.
      - [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md) 0x004cf300-0x004cf3d3 | virtual paint method | IconsPaneOnPaint : reconstructable : 86% : very-strong : Virtual paint handler at vtable slot `0x0061b48c`; draws `ICONS.EPD` through `NPAL7.PAL`, starts at icon `0` in full mode or `6` in reduced mode, uses frame `index+8` when `m_selectedIconIndex` matches and `m_isPressed` is set, and remains C++-deferred only for shared render-helper names.
      - [UID:0002T3][0x004cf7d0-0x004cf862.IconsPaneHitTestIcon](by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md) 0x004cf7d0-0x004cf862 | helper method | IconsPaneHitTestIcon : reconstructable : 86% : very-strong : Hit-test helper called four times from `OnMouseEvent`; maps event coordinates to icon indexes using 20-pixel slots, starts at index `0` or `6` according to `m_showAllIcons`, returns `-1` on miss, and is followed by `0x004cf862-0x004cf870` padding.
      - [UID:0002T4][0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight](by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md) 0x004cf870-0x004cf8d5 | helper method | IconsPaneSetIconHighlight : reconstructable : 86% : very-strong : Pressed/highlight helper called four times from `OnMouseEvent`; compares requested state with `m_isPressed`, invalidates the selected icon rectangle computed from `m_selectedIconIndex * 20`, and then stores the new state.
```

New coverage rows needed after the supervisor allocates UIDs:

```markdown
      - [UID:NEW][0x004cf74b-0x004cf7a0.IconsPaneOnMouseEventSwitchTables](by-memory/0x004cf74b-0x004cf7a0.IconsPaneOnMouseEventSwitchTables.md) 0x004cf74b-0x004cf7a0 | compiler switch data | IconsPaneOnMouseEventSwitchTables : non-reconstructable : 86% : strong : Embedded `OnMouseEvent` switch data: one-byte `nop`, five-entry event-mode jump table at `0x004cf74c`, eight-entry tooltip table at `0x004cf760`, and eight-entry click-action table at `0x004cf780`; source behavior is represented by `OnMouseEvent`, not by a standalone C++ body.
      - [UID:NEW][0x004cf7a0-0x004cf7c9.IconsPaneBuildIconRectRawHelper](by-memory/0x004cf7a0-0x004cf7c9.IconsPaneBuildIconRectRawHelper.md) 0x004cf7a0-0x004cf7c9 | retained raw helper | IconsPaneBuildIconRectRawHelper : reconstructable : 84% : medium-strong : Function-shaped no-xref helper that fills an icon rectangle as `{left=index*20, top=0, right=index*20+19, bottom=14}`; direct branch, VA-pointer, and RVA-pointer scans found no route, so keep as retained `IconsPane.cpp` geometry evidence with blank/marker-only C++ unless liveness is later proven.
      - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004cf7c9-0x004cf7d0 | padding | IconsPaneBuildIconRectRawHelper to IconsPaneHitTestIcon alignment : ignored : 100% : strong : Seven `0xcc` alignment bytes after the no-xref icon-rectangle helper and before `IconsPane::HitTestIcon`.
```

Because B003 cannot allocate new UIDs, replace `NEW` only after the supervisor creates those child pages.

## Validator Needs

- The validator should distinguish aggregate/index pages from source functions. [UID:00016Z] should be allowed to emit a marker-only comment while exact child pages emit real method bodies.
- The validator/coverage pass should flag the currently missing `0x004cf74b-0x004cf7d0` coverage if no child/padding rows are created.
- If marker-only aggregate C++ is accepted, `auto-generated/-ag-memory-coverage.md` may show `Code=yes` for [UID:00016Z]. If comments are not counted, keep `Code=no` but do not fail the aggregate when exact children cover source bodies.
- Regenerate coverage after adding the gap split; the current `by-memory/-coverage-report.md` still has stale child scores (`78`, `76`) for several IconsPane child rows.

## IDA Rename / Type / Comment Recommendations

High-confidence names:

- `sub_4CF1F0` -> `IconsPane::IconsPane`
- `sub_4CF260` -> `IconsPane::CleanupForDestruction` or `IconsPaneCleanupHelper`
- `sub_4CF290` -> `IconsPane::IsShowingAllIcons`
- `sub_4CF2A0` -> `IconsPane::ShowAllIcons`
- `sub_4CF2D0` -> `IconsPane::ShowReducedIcons`
- `sub_4CF300` -> `IconsPane::OnPaint`
- `sub_4CF3E0` -> `IconsPane::OnMouseEvent`
- `sub_4CF7D0` -> `IconsPane::HitTestIcon`
- `sub_4CF870` -> `IconsPane::SetIconHighlight`
- `dword_69B41C` -> `g_pIconsPane`
- `dword_67A7C8` -> `g_pConfig`
- `dword_67A748` -> `g_pCollectionData`
- `dword_67A764` -> `g_activeMapPane`
- `dword_67A744` -> `g_pEPFLib`
- `dword_67A750` -> `g_pLanguageMan`

Medium-confidence names/comments:

- `0x004cf74c` -> `IconsPane_OnMouseEvent_EventSwitchTable`
- `0x004cf760` -> `IconsPane_OnMouseEvent_TooltipSwitchTable`
- `0x004cf780` -> `IconsPane_OnMouseEvent_ClickActionSwitchTable`
- `sub_4CF7A0` if made a function -> `IconsPane_BuildIconRectForIndex_RawNoXref`
- Comment at `0x004cf7a0`: `No direct branch or VA/RVA pointer hits in PE scan; duplicates icon-slot rectangle math used by hit-test/highlight.`
- `0x004cf8e0` -> `IconsPaneActionDispatchRawBody_NoXref` if IDA function is defined for analysis only.
- Comment at `0x004cf8e0`: `No entrypoint refs or pointer hits; mirrors IconsPane::OnMouseEvent click switch.`

Helper behavior labels:

- `sub_5A4DB0` -> `SwitchGeneralPurposePanelMode2WithClickSound`
- `sub_5A4E40` -> `SwitchGeneralPurposePanelMode3WithClickSound`
- `sub_5A4F70` -> `SendOpcode2DAndStoreExtra`
- `sub_5A5010` -> `SyncNationEntriesOrDeferredState` / `ProcessDeferredSendState`
- `sub_5A50A0` -> `EnsureNormalBulletinSession`
- `sub_5A5110` -> `OpenInputPaneForCurrentSayMode`
- `sub_5A5340` -> `SendOpcode43MinusOneRequest`
- `sub_5A5A80` -> `OpenQuitPromptThunk`

Types to standardize:

```cpp
class IconsPane : public Pane {
    bool m_showAllIcons;       // +0xf8
    int m_selectedIconIndex;   // +0xfc
    bool m_isPressed;          // +0x100
};

// Config / RegistryConfig field direction:
// byte m_iconPaneReducedMode; // g_pConfig + 0x28de32, 0 full, 1 reduced
```

## Open Questions

1. Exact original spelling for `g_pConfig + 0x28de32`.
   - Best answer: `m_iconPaneReducedMode` because the stored byte is `1` only for reduced mode. Use neutral `m_iconPaneDisplayMode` if the config layout uses mode/value names.
   - Evidence checked: constructor, show setters, OptionPane callers, central `g_pConfig` field cluster.

2. Was `0x004cf7a0` source-authored and dead, or compiler-retained static helper data?
   - Best answer: source-shaped retained no-xref helper in `IconsPane.cpp`.
   - Evidence checked: direct PE branch/pointer scans found no route; body exactly builds the known icon rectangle.

3. Was [UID:00022Q] originally a callable helper?
   - Best answer: not proven; current evidence supports retained duplicate/action-dispatch raw body.
   - Evidence checked: no IDA function object in docs, no direct PE route, local-only jump-table pointer, duplicate helper order in live `OnMouseEvent`.

4. Final UI labels for the eight icon actions.
   - Best answer: do not infer UI labels from position alone. Use behavior names until resource/menu evidence is reviewed.

5. Whether `IconsPane.cpp` and `TabPane.cpp` were one original source file.
   - Best answer: separate docs/files remain best. Adjacency and shared action helpers are weaker than class/singleton/vtable/resource ownership.

## Validation Commands Needed

Read-only documentation checks:

> Executable block R001 was removed from this report and preserved verbatim in [00016Z-IconsPaneCore-source-quality-removed.md](00016Z-IconsPaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Direct binary validation:

> Executable block R002 was removed from this report and preserved verbatim in [00016Z-IconsPaneCore-source-quality-removed.md](00016Z-IconsPaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validator/autogen checks after implementation:

> Executable block R003 was removed from this report and preserved verbatim in [00016Z-IconsPaneCore-source-quality-removed.md](00016Z-IconsPaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation Readiness

- Ready for supervisor implementation callback: yes.
- Safe first implementation steps:
  - Update target/support docs only, no source-generation behavior changes yet.
  - Add or request exact child pages for `0x004cf74b-0x004cf7a0` and `0x004cf7a0-0x004cf7c9`; add ignored padding `0x004cf7c9-0x004cf7d0`.
  - Add marker-only C++ to [UID:00016Z] if the validator requires eligible emitters to have a non-empty block.
- Not ready for full child method C++ in this callback unless the supervisor explicitly asks for implementation beyond the B report. The aggregate itself should not receive method-body C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00016Z-IconsPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"00016Z"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00016Z-IconsPaneCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00016Z-IconsPaneCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00016Z"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
