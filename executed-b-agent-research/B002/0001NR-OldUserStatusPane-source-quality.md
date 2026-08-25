** TARGET-REPORT-UID:0001NR **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Report - [UID:0001NR] OldUserStatusPane Source Quality

Assignment: `B002-rework-report-0001NR-OldUserStatusPane-source-quality-20260627`
Agent: `B002`
Mode: rejected-report amendment, report-only. No target/support by-* documents were edited.
Target: [UID:0001NR] `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md`

## Current Target State

- Current metadata in the target page: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009U`, blank formal C++.
- Current owner route: [UID:0001NR] -> [UID:00009U] `OldUserStatusPane` -> [UID:0000P2] `UserStatusPane`.
- Current support metadata:
  - [UID:00009U] `by-class/OldUserStatusPane.md`: `85/86`, owner/emitter [UID:0000P2], blank formal C++.
  - [UID:0000P2] `by-file/UserStatusPane.md`: `88/85`, proposed path `NexusTK/ui/panels/`.
  - [UID:0000RV] `by-global/g_pOldUserStatusPane.md`: `86/90`, owner/emitter [UID:0000P2], blank formal C++.
  - [UID:0001NS] shared destructor/thunk tail: `86/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`.
- Current target summary still says final C++ is blocked by provisional helper/field names, malformed generated constructor text, generated-output omissions, trailing alignment row treatment, and no fresh MCP. This pass resolves those as current implementation items instead of leaving them as open blockers.
- Current generated tracker/autogen state is stale versus source docs: `auto-generated/-ag-research-tracker.md` lists [UID:0001NR] as `82/85`, and generated `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` contains only empty emitter markers for [UID:0001NR] and [UID:00009U]. The old `source-3/simroot_v2/class_OldUserStatusPane.cpp` path named by support docs is not present in the current worktree.

## MCP And Documentation Evidence Checked

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Live IDB session: `b001_000241_20260627`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker session, `is_analyzing:false`.
- MCP tools used in this pass: `idb_list`, `lookup_funcs`, `xrefs_to`, `find` with `code_ref` and `data_ref`, `get_bytes`, `insn_query`, `disasm`, plus earlier same-session function analysis/decompilation evidence for the constructor, cleanup, router, hover handler, paint, rectangle lookup, glyph helper, and payload updater.
- Docs checked: target page, [UID:00009U] `OldUserStatusPane`, [UID:0000P2] `UserStatusPane`, [UID:0000RV] `g_pOldUserStatusPane`, [UID:0001NS] shared tail, resource pages, generated `UserStatusPane.cpp`, current generated tracker rows, and relevant executed reports for TotemFrame/UserStatusPane context.
- Existing report context checked: B005 `0001KC-TotemFrame-source-quality.md` validates `g_pOldUserStatusPane->GetSpiritId()` as the TotemFrame frame selector and leaves only the exact spirit-to-resource-frame semantic mapping open; B001 `0002BF-WideGlyphResourceTextRendererRaw-B001-0002BF.md` confirms the `0x005bf3b0` 9x11 glyph helper matches the shared wide-glyph renderer pattern.

## Corrected Range And Split Map

The target is a valid OldUserStatusPane class-method aggregate, but its current covered-range table is incomplete. It omits one unmodeled invalidate wrapper and three unmodeled retained packet helper bodies inside the aggregate. Those are not "needs investigation" blockers anymore; the exact disposition is below.

| Range | Recommended role | Evidence and disposition |
| --- | --- | --- |
| `0x005bda40-0x005bdb63` | `OldUserStatusPane::OldUserStatusPane` | Modeled function `sub_5BDA40`, called from `InitializeMainUiGraph` at `0x004f8951`; publishes `g_pOldUserStatusPane`, installs three OldUserStatusPane vtables, loads `9X11FONT.BIN`, copies the display name, initializes status fields. |
| `0x005bdb70-0x005bdbed` | `OldUserStatusPane` cleanup body | Frees the `+0xf8` glyph table through image/free helpers, clears `g_pOldUserStatusPane`, calls pane-base cleanup. |
| `0x005bdc30-0x005bdc88` | accessors and setter | Accessor callers prove `+0x13c` is the legacy nation id, `+0x13e` is the spirit/totem id used by TotemFrame, and `+0x13f` is the status icon id set by LivingObjectPane. |
| `0x005bdcb0-0x005bdf3c` | packet/movement router | Vtable-reached router. Handles opcode `0x04` position update, `0x08` status payload forwarding, and movement variants `0x0b`/`0x26`. |
| `0x005bdfa0-0x005be51e` | hover/help handler | Handles old status help zones and localized help-pane creation. |
| `0x005be520-0x005bf10d` | paint method | Draws `USERSTAT.EPD`, `NATION.EPD`, `TOTEM.EPD`, `CLASS.EPD`, bars, numbers, title text, and old HUD palettes. |
| `0x005bf10d-0x005bf110` | alignment | MCP `get_bytes` shows three `0xcc` bytes before the next raw body. |
| `0x005bf110-0x005bf14b` | raw invalidate-status-rect wrapper | Not modeled as an IDA function, no code/data refs to the raw entry. `insn_query` shows it calls `0x005bf150` to fill a local rect for a field id, then calls virtual slot `+0x20` on `this` with that rect and returns `retn 4`. Best source-facing name: `InvalidateStatusFieldRect(int fieldId)`. |
| `0x005bf14b-0x005bf150` | alignment | `0xcc` padding after the wrapper and before modeled rect lookup. |
| `0x005bf150-0x005bf374` | `GetStatusFieldRect` / legacy status-rect lookup helper | Modeled function `sub_5BF150`, 13-case switch mapping field ids to exact dirty/help rectangles. Called by the raw wrapper at `0x005bf12a`; no other direct caller found in the live refs. |
| `0x005bf374-0x005bf3b0` | jump table / alignment for `0x005bf150` | Keep with the rect lookup helper. It is not independent source logic. |
| `0x005bf3b0-0x005bf481` | `DrawNumberGlyphString` | Modeled helper with nine paint-call refs. Uses the constructor-loaded `9X11FONT.BIN` table, skips space and slash, advances by 9 pixels. |
| `0x005bf481-0x005bf490` | alignment | `get_bytes` shows fifteen `0xcc` bytes before the raw position helper. |
| `0x005bf490-0x005bf51a` | raw retained position-update helper | Not modeled as a function; no code/data refs to entry; reads big-endian x/y from payload offsets `+1` and `+3`, updates offsets `+0x15c`/`+0x160`, invalidates rect `(101,82,192,94)`, returns `0`. Duplicates router opcode `0x04` behavior. Best source-facing name if emitted as a file-local retained helper: `ApplyLegacyPositionPacket`. |
| `0x005bf51a-0x005bf520` | alignment | `0xcc`/alignment between raw helper bodies. |
| `0x005bf520-0x005bf660` | raw retained movement-step helper | Not modeled as a function; no code/data refs to entry; reads direction byte, big-endian x/y, active map pane bounds, and config byte `dword_67A7C8+0x28de75`, then clamps/stores `+0x15c`/`+0x160` and invalidates the same position rect. Duplicates one router movement branch. Best source-facing name: `ApplyLegacyMovementStep`. |
| `0x005bf660-0x005bf670` | jump table for `0x005bf520` | Internal jump table only; `xrefs_to` reports the only ref from `0x005bf5d3`. Keep with the preceding raw helper, not as data owned by another file. |
| `0x005bf670-0x005bf7b0` | raw retained movement-step variant | Same source role as `0x005bf520`, with an independent jump table. No entry refs. Best source-facing name: `ApplyLegacyMovementStepAlt` or document as retained duplicate of the movement helper for the second packet opcode. |
| `0x005bf7b0-0x005bf7c0` | jump table for `0x005bf670` | Internal jump table only; `xrefs_to` reports the only ref from `0x005bf723`. |
| `0x005bf7c0-0x005bfbc1` | `ApplyLegacyStatusPayload` | Modeled function called from the router at `0x005bdf24`. Parses bitflags, updates nation/spirit/class/status/stat/bar/position fields, invalidates field rectangles, creates/invalidates `TotemFrame`. |
| `0x005bfbc1-0x005bfbd0` | alignment before shared tail | MCP `get_bytes` returns only `0xcc`; keep this as ignored/alignment, not C++. |

## Behavior And Source-Facing Names

- `OldUserStatusPane::OldUserStatusPane` should remain the source constructor name. It takes the display-name/source label string, not a generic decompiler `Source` field. Recommended field name for `+0xfc`: `m_displayName`.
- The constructor-loaded pointer at `+0xf8` should be documented as the loaded numeric glyph table, preferably `m_numberGlyphs` or `m_numberGlyphImage`. It is loaded from `9X11FONT.BIN` and used only by `DrawNumberGlyphString`.
- `0x005bdc30` should be named `GetNationId()`.
- `0x005bdc60` should remain `GetSpiritId()` because TotemFrame uses it as the `TOTFRAME.EPD` frame selector; `GetTotemId()` is a plausible synonym but current support docs and caller semantics already favor `GetSpiritId`.
- `0x005bdc70` should be named `SetStatusIconId(int iconId)` or `SetStatusIcon(byte iconId)`, because it writes `+0x13f` and invalidates the top status-icon rectangle.
- `0x005bf150` is best named `GetStatusFieldRect(int fieldId, RectBounds *outRect)`, using the existing `sub_4B7C50`/`RectBounds` evidence rather than a raw address helper name.
- `0x005bf110` is best documented as `InvalidateStatusFieldRect(int fieldId)`, a thin member wrapper around the rect lookup and virtual invalidation.
- `0x005bf3b0` should stay `DrawNumberGlyphString`, not a generic renderer. It draws 9x11 glyphs from `9X11FONT.BIN`, skips spaces and slashes, and advances by 9 pixels.
- `0x005bf7c0` should be named `ApplyLegacyStatusPayload` or `ApplyStatusPayload`. The "legacy" qualifier is useful because `UserStatusPane` and `UserStatusPane2` have newer sibling status packet paths in the same source module.
- The raw `0x005bf490`, `0x005bf520`, and `0x005bf670` bodies should not stay unnamed in documentation. Treat them as retained, no-entry, source-shaped packet helpers under OldUserStatusPane, with exact no-entry evidence, source-facing names, required child pages, and the formal first-draft C++ blocks supplied below.
- `dword_67A764` in the movement helpers should be described as the active map/map-pane state used for map bounds. `dword_67A7C8+0x28de75` should be described as a config byte that controls high-bit direction handling. These are not OldUserStatusPane-owned globals.

## Field And Packet Layout Reanalysis

| Offset | Best current source-facing role | Evidence |
| --- | --- | --- |
| `+0xf8` | `m_numberGlyphs` / loaded 9x11 glyph table | Constructor loads `9X11FONT.BIN`; cleanup frees this pointer; glyph helper indexes it. |
| `+0xfc` | `m_displayName[16]` | Constructor copies a 16-wide-character display label; paint draws the title/name area. |
| `+0x13c` | `m_nationId` | Accessor `0x005bdc30`, UserListDialog constructor caller, nation resource painting. |
| `+0x13e` | `m_spiritId` | Accessor `0x005bdc60`, TotemFrame paint caller, `TOTEM.EPD`/`TOTFRAME.EPD` dependency. |
| `+0x13f` | `m_statusIconId` | Setter `0x005bdc70`, LivingObjectPane caller, top status-icon invalidation. |
| `+0x140` | `m_classId` | Status payload updates this byte and invalidates the `CLASS.EPD` icon rectangle `(160,3,190,15)`. |
| `+0x141`, `+0x142`, `+0x143` | three compact old-status attribute/icon bytes | Status payload updates and invalidates the three small rectangles `(75,17,102,29)`, `(163,17,190,29)`, and `(120,17,147,29)`. Exact original names remain inferred; do not leave them as raw byte offsets in final source. |
| `+0x144`, `+0x148`, `+0x14c`, `+0x150`, `+0x154`, `+0x158` | old status bar/value fields | Payload flags update these dword values and invalidate rows `(101,30,192,42)`, `(101,43,192,55)`, `(101,56,192,68)`, and `(101,69,192,81)`. Best source-facing names should be row/value based until an exact UI text/resource audit proves the original labels. |
| `+0x15c`, `+0x160` | `m_mapX`, `m_mapY` or `m_positionX`, `m_positionY` | Router and raw helpers update these from big-endian packet words and invalidate `(101,82,192,94)`. |

Packet disposition:
- Router opcode `0x04`: direct position update from payload offsets `+1` and `+3`.
- Router opcode `0x08`: full/partial old status payload, forwarded to `ApplyLegacyStatusPayload`.
- Router opcodes `0x0b` and `0x26`: movement step variants using direction byte, active map bounds, and config high-bit handling.
- The raw helper bodies at `0x005bf490`, `0x005bf520`, and `0x005bf670` duplicate those router cases but have no direct entry refs. They are retained source-shaped bodies, not padding and not independent ownership.

## Positive Evidence

- Constructor caller `0x004f8951` in `InitializeMainUiGraph` routes this class to the status-pane source family, not to adjacent MenuVariety code.
- `g_pOldUserStatusPane` has nine direct xrefs covering constructor publication, cleanup/destructor clears, map-exit teardown, TotemFrame, UserListDialog, and LivingObjectPane consumers.
- `OldUserStatusPane` class and `UserStatusPane` file pages already clear the parent route gate.
- Resource string/xref evidence ties this target to `USERSTAT.EPD`, `NATION.EPD`, `TOTEM.EPD`, `CLASS.EPD`, `BAR.EPD`, `9X11FONT.BIN`, `NPAL7.PAL`, and `NPAL5.PAL`.
- Vtable data [UID:0002Z3] routes the router and paint methods to OldUserStatusPane vtable slots.
- `0x005bf3b0` has nine direct paint-call refs and a distinctive 9x11 glyph rendering pattern.
- MCP now proves the trailing `0x005bfbc1-0x005bfbd0` range is pure `0xcc` alignment and belongs outside formal source C++.

## Negative Evidence And Rejected Alternatives

- Reject `CANONICAL_OWNER:NONE`: constructor, singleton, vtables, status resources, class page, and source-file grouping all support direct OldUserStatusPane ownership.
- Reject MenuVariety ownership: the address-adjacent menu hit-test helper ends before `0x005bda40`, and `0x005bda3b-0x005bda40` is only padding.
- Reject assigning the shared tail [UID:0001NS] to OldUserStatusPane: the tail mixes MenuVariety, OldUserStatusPane, UserStatusPane2, UserStatusPane, compiler adjustor thunks, scalar deleting destructors, and a MenuVariety vector helper.
- Reject treating `0x005bf110`, `0x005bf490`, `0x005bf520`, or `0x005bf670` as padding: MCP `insn_query` shows valid security-cookie member/helper bodies.
- Reject treating the raw helper entries as live externally reached methods: `xrefs_to` and `find code_ref`/`find data_ref` show no code/data refs to `0x005bf110`, `0x005bf490`, `0x005bf520`, or `0x005bf670`; only internal jump table refs point to `0x005bf660` and `0x005bf7b0`.
- Reject old malformed constructor text as source evidence: current `source-3/simroot_v2/class_OldUserStatusPane.cpp` is absent, and current generated `UserStatusPane.cpp` has marker-only output for this target. The malformed-constructor issue should be documented as stale generated-output pollution, not a live source input.

## Heuristic / Inference Reanalysis And Validation

- Helper/field names: resolved to best current source-facing names above. Exact original spellings are not proven, but the report provides non-IDA names based on binary behavior and subsystem style. Do not leave `sub_`, `dword_`, or raw offset labels in implementation prose except when citing IDA evidence.
- Malformed generated constructor text: resolved as stale/superseded generated output. The implementation should replace the target/class/file caveat with current evidence: old simroot file absent; active autogen is marker-only and stale; no source conclusion should depend on literal `` `n`n`` text.
- Generated-output omissions: resolved as a source metadata/generated-refresh issue. Current source docs have better scores than generated markers, but the formal C++ block is blank, so generated output remains marker-only. Implementation should update docs and metadata first, then supervisor should validate and refresh generated reports through the validator.
- Alignment/tail treatment: resolved. `0x005bf10d-0x005bf110`, `0x005bf14b-0x005bf150`, `0x005bf481-0x005bf490`, `0x005bf51a-0x005bf520`, and `0x005bfbc1-0x005bfbd0` are alignment/padding; `0x005bf660-0x005bf670` and `0x005bf7b0-0x005bf7c0` are internal jump tables owned by the preceding raw helpers.
- Source split: resolved to required exact child pages under the [UID:0001NR] aggregate. The aggregate should no longer be treated as the place where helper/method bodies might someday be emitted. It must become a `[[CHILDREN]]` aggregation point, and the exact child pages listed in `Required Split And Source-Emission Plan` must carry the method/helper formal C++ or the specific range no-code proof.
- Owner/emitter route: keep [UID:00009U] as canonical owner and emitter. The direct source module remains [UID:0000P2] `UserStatusPane`.
- Formal C++ readiness: [UID:0001NR] must not keep an empty emitter marker. Its required formal block is exactly `[[CHILDREN]]`, while the child pages below own the source bodies. This is required implementation repair for the aggregate-C++ blocker, not deferred follow-up.

## Score And Metadata Recommendation

Recommended after implementation:

- [UID:0001NR] `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md`: raise `COMPLETION:85 -> 89`, raise `CONFIDENCE:88 -> 91`, keep `CANONICAL_OWNER:00009U`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00009U`, and replace the blank formal C++ with an aggregate-only `[[CHILDREN]]` block. Rationale: [UID:0001NR] is still a real source-bearing OldUserStatusPane aggregate, but its direct source contribution is an insertion point for exact children, not a monolithic method body.
- [UID:00009U] `by-class/OldUserStatusPane.md`: raise `COMPLETION:85 -> 88`, raise `CONFIDENCE:86 -> 90`, keep owner/emitter [UID:0000P2], add the required child method/helper signatures, and add a declaration-level class shell with `[[CHILDREN]]` so exact by-memory children can carry body emission.
- [UID:0000P2] `by-file/UserStatusPane.md`: keep `88/85`; update Data Caveats/Method Families with the stale generated-output correction and raw helper disposition, but do not raise the file score from this target alone.
- [UID:0000RV] `by-global/g_pOldUserStatusPane.md`: no score change required; the global already documents the xref/lifetime route at adequate detail.
- [UID:0001NS] shared tail: no score or ownership change required; only cross-reference from [UID:0001NR] should remain clear that the tail starts at `0x005bfbd0`.

Rationale for raising [UID:0001NR]: this pass resolves every named blocker into concrete source-quality text and a required split/emission plan: raw helper liveness, helper names, field roles, stale generated constructor issue, generated-output omissions, alignment/tail treatment, owner/emitter route, parent `[[CHILDREN]]`, and child formal C++ routing. It still should not exceed low-90s because the implementation callback must still create/validate the new child pages and the large paint/router/status field names remain inferred rather than final-audit proven.

## Recommended Target/Support Doc Changes

For [UID:0001NR] target page:

1. Replace the Item Summary with a current MCP-backed summary, for example:
   `Legacy OldUserStatusPane class-method aggregate attached to [UID:00009U]; current MCP confirms constructor/cleanup/accessor/router/hover/paint/rect/glyph/payload bodies, the previously omitted raw invalidate wrapper and retained packet helper island, exact alignment/jump-table/tail boundaries, status-resource dependencies, singleton lifecycle, and source route through [UID:0000P2]. This aggregate emits only a formal [[CHILDREN]] insertion point; exact method/helper body emission is required on the child by-memory pages listed in the B002 split plan.`
2. Add covered rows for `0x005bf10d-0x005bf110`, `0x005bf110-0x005bf14b`, `0x005bf14b-0x005bf150`, `0x005bf374-0x005bf3b0`, `0x005bf481-0x005bf490`, `0x005bf490-0x005bf51a`, `0x005bf51a-0x005bf520`, `0x005bf520-0x005bf660`, `0x005bf660-0x005bf670`, `0x005bf670-0x005bf7b0`, and `0x005bf7b0-0x005bf7c0`.
3. Replace stale "no fresh MCP" and malformed generated-constructor blockers with the current MCP evidence and stale-generated-output explanation.
4. Add the field/packet/source-facing-name table from this report.
5. Replace the blank aggregate C++ with the exact parent insertion block:

```cpp
[[CHILDREN]]
```

6. Add the split policy under Ownership/Reconstruction notes: [UID:0001NR] owns the aggregate ordering and evidence, while exact children own body C++ or child-specific no-code proofs.

For [UID:00009U] class page:

1. Add the raw `0x005bf110` invalidate wrapper, raw retained packet helper island, and internal jump table ranges to the Method Map.
2. Replace the generated-output caveat with current wording: active generated output is marker-only/stale; old simroot constructor text is stale/superseded evidence and should not drive source decisions.
3. Add/update class field evidence for `m_displayName`, `m_numberGlyphs`, `m_nationId`, `m_spiritId`, `m_statusIconId`, `m_classId`, status value rows, and position fields.
4. Add required source-split note: class page should list the child method/helper signatures and route body emission through exact child pages, not through the broad aggregate body.

For [UID:0000P2] file page:

1. Update Data Caveats to state that `class_OldUserStatusPane.cpp` in old `simroot_v2` is absent in the current worktree and active generated output is marker-only for this class, so the literal `` `n`n`` constructor caveat is historical generated pollution.
2. Add a Source-Layout note that OldUserStatusPane has retained no-entry packet helper bodies in the same source family and should remain in `UserStatusPane.cpp`, not be routed to MenuVariety or the shared destructor tail.

Generated/manual coverage:

- Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/NexusTK/**`, `project-level/**`, or any manual `-coverage-report.md` file from B002.
- Supervisor should refresh generated state by scoped validators after implementation. No explicit manual coverage-report row is required from this B-agent report unless the supervisor separately asks for manual coverage text.

## Required Split And Source-Emission Plan

This split is required for supervisor acceptance. [UID:0001NR] remains the OldUserStatusPane aggregate and emits only `[[CHILDREN]]`; it does not own monolithic body C++. Each child below should be created during the implementation callback as a new `by-memory` page. The child UID is `validator-created/TBD` until the file is created and validated; do not guess UIDs in support docs before the validator assigns them. Use temporary references if a parent/support page must link to the new file before UID assignment.

Required parent aggregate formal block for [UID:0001NR]:

```cpp
[[CHILDREN]]
```

Parent metadata after implementation:

| Field | Required value |
| --- | --- |
| `COMPLETION` | `89` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | `00009U` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `00009U` |
| `RECONSTRUCTION_CPP CODE` | `[[CHILDREN]]` only |

Required child pages:

| Required path | Range | UID disposition | Metadata | Source role | Formal C++ / no-code disposition |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x005bf110-0x005bf14b.OldUserStatusPaneInvalidateStatusFieldRect.md` | `0x005bf110-0x005bf14b` | validator-created/TBD | `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR` | Member wrapper that maps a status field id to a rectangle and invalidates it through the pane virtual invalidation slot. | Emit the formal C++ block below. |
| `by-memory/0x005bf150-0x005bf3b0.OldUserStatusPaneStatusFieldRectLookup.md` | `0x005bf150-0x005bf3b0` | validator-created/TBD | `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR` | Member/static helper that maps old status field ids to exact dirty/help rectangles. The `0x005bf374-0x005bf3b0` jump-table/alignment tail belongs to this switch helper. | Emit the formal C++ block below. |
| `by-memory/0x005bf3b0-0x005bf481.OldUserStatusPaneDrawNumberGlyphString.md` | `0x005bf3b0-0x005bf481` | validator-created/TBD | `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR` | 9x11 numeric glyph renderer over the constructor-loaded `9X11FONT.BIN` table. | Emit the formal C++ block below. |
| `by-memory/0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket.md` | `0x005bf490-0x005bf51a` | validator-created/TBD | `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR` | Retained no-entry position packet helper for legacy opcode `0x04`; updates the old map position fields and invalidates field id `12`. | Emit the formal C++ block below. |
| `by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md` | `0x005bf520-0x005bf670` | validator-created/TBD | `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR` | Retained no-entry movement helper for one legacy movement opcode; includes its internal jump table at `0x005bf660-0x005bf670`. | Emit the formal C++ block below. |
| `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md` | `0x005bf670-0x005bf7c0` | validator-created/TBD | `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR` | Retained no-entry movement helper variant for the sibling legacy movement opcode; includes its internal jump table at `0x005bf7b0-0x005bf7c0`. | Emit the formal C++ block below. |
| `by-memory/0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md` | `0x005bf7c0-0x005bfbc1` | validator-created/TBD | `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001NR` | Live status-payload applicator called from the packet router; updates old status fields, invalidates rectangles, and creates/invalidates `TotemFrame`. | Emit the formal C++ block below. |

Padding/jump-table ownership treatment:

- Do not create standalone reconstructable pages for `0x005bf10d-0x005bf110`, `0x005bf14b-0x005bf150`, `0x005bf481-0x005bf490`, `0x005bf51a-0x005bf520`, or `0x005bfbc1-0x005bfbd0`; document them as `0xcc` alignment in [UID:0001NR] and, if the implementation callback requires an ignored ledger entry, add only supervisor-approved ignored/padding rows.
- Do not create standalone source items for `0x005bf374-0x005bf3b0`, `0x005bf660-0x005bf670`, or `0x005bf7b0-0x005bf7c0`; each is an internal switch/jump-table/alignment island owned by the preceding helper child.
- The raw helper children have no external entry xrefs, but they are valid source-shaped retained code inside the OldUserStatusPane aggregate. Their no-entry evidence should be preserved in each child page; it is not a reason to skip the child or leave it unnamed.

Required support declarations/names for the child C++ blocks:

- [UID:00009U] class docs should list the helper signatures exactly as `InvalidateStatusFieldRect`, `GetStatusFieldRect`, `DrawNumberGlyphString`, `ApplyLegacyPositionPacket`, `ApplyLegacyMovementStep`, `ApplyLegacyMovementStepAlt`, and `ApplyLegacyStatusPayload`.
- [UID:00009U] / [UID:0000P2] support docs should document these inferred support names used by the child C++ blocks: `RectBounds`, `InitRectBounds`, `ReadPacketInt16BE`, `ReadPacketUInt32BE`, `RenderTileFrame`, `GetLegacyMovementBounds`, `ShouldMaskLegacyMovementDirection`, `g_pTotemFrame`, `g_activeMapPane`, and `g_pGameConfig`. These names are source-facing inferred names; IDA labels remain evidence only.

Required declaration-level formal C++ block for [UID:00009U] `by-class/OldUserStatusPane.md`:

```cpp
class OldUserStatusPane : public Pane
{
public:
    explicit OldUserStatusPane(const wchar_t *displayName);
    virtual ~OldUserStatusPane();

    unsigned char GetNationId() const;
    signed char GetSpiritId() const;
    void SetStatusIconId(unsigned char iconId);

    void InvalidateStatusFieldRect(int fieldId);
    void GetStatusFieldRect(int fieldId, RectBounds *bounds);
    void DrawNumberGlyphString(const wchar_t *text, int x, int y, int glyphRow);
    bool ApplyLegacyPositionPacket(const unsigned char *packet);
    bool ApplyLegacyMovementStep(const unsigned char *packet);
    bool ApplyLegacyMovementStepAlt(const unsigned char *packet);
    void ApplyLegacyStatusPayload(const unsigned char *packet);

private:
    void *m_numberGlyphs;
    wchar_t m_displayName[16];
    unsigned char m_nationId;
    signed char m_spiritId;
    unsigned char m_statusIconId;
    unsigned char m_classId;
    unsigned char m_attributeLeft;
    unsigned char m_attributeCenter;
    unsigned char m_attributeRight;
    unsigned int m_primaryValue;
    unsigned int m_primaryMaximum;
    unsigned int m_secondaryValue;
    unsigned int m_secondaryMaximum;
    unsigned int m_tertiaryValue;
    unsigned int m_tertiaryMaximum;
    int m_positionX;
    int m_positionY;
};

[[CHILDREN]]
```

Class declaration caveat for supervisor validation: field order/packing in this first-draft declaration is source-facing and should be documented as inferred from offsets. The class page should not be scored above final-audit thresholds until the complete inherited layout and all unnamed status rows are reconciled, but this does not block adding the declaration shell and child insertion route now.

### Formal C++ Blocks For Required Children

These are first-draft formal block texts for the child pages. They are not prose examples; if accepted, they should be inserted into the listed child pages' formal `RECONSTRUCTION_CPP CODE` blocks during the implementation callback. They intentionally use source-facing inferred names rather than IDA labels.

#### `0x005bf110-0x005bf14b.OldUserStatusPaneInvalidateStatusFieldRect.md`

```cpp
void OldUserStatusPane::InvalidateStatusFieldRect(int fieldId)
{
    RectBounds bounds;
    GetStatusFieldRect(fieldId, &bounds);
    InvalidateRect(&bounds);
}
```

#### `0x005bf150-0x005bf3b0.OldUserStatusPaneStatusFieldRectLookup.md`

```cpp
void OldUserStatusPane::GetStatusFieldRect(int fieldId, RectBounds *bounds)
{
    switch (fieldId)
    {
    case 0:
        InitRectBounds(bounds, 59, 3, 131, 15);
        break;
    case 1:
        InitRectBounds(bounds, 1, 49, 56, 94);
        break;
    case 2:
        InitRectBounds(bounds, 1, 2, 56, 47);
        break;
    case 3:
        InitRectBounds(bounds, 147, 0, 193, 17);
        break;
    case 4:
        InitRectBounds(bounds, 160, 3, 190, 15);
        break;
    case 5:
        InitRectBounds(bounds, 75, 17, 102, 29);
        break;
    case 6:
        InitRectBounds(bounds, 163, 17, 190, 29);
        break;
    case 7:
        InitRectBounds(bounds, 120, 17, 147, 29);
        break;
    case 8:
        InitRectBounds(bounds, 101, 30, 192, 42);
        break;
    case 9:
        InitRectBounds(bounds, 101, 43, 192, 55);
        break;
    case 10:
        InitRectBounds(bounds, 101, 56, 192, 68);
        break;
    case 11:
        InitRectBounds(bounds, 101, 69, 192, 81);
        break;
    case 12:
        InitRectBounds(bounds, 101, 82, 192, 94);
        break;
    default:
        InitRectBounds(bounds, 0, 0, 0, 0);
        break;
    }
}
```

#### `0x005bf3b0-0x005bf481.OldUserStatusPaneDrawNumberGlyphString.md`

```cpp
void OldUserStatusPane::DrawNumberGlyphString(const wchar_t *text, int x, int y, int glyphRow)
{
    RectBounds sourceBounds;
    InitRectBounds(&sourceBounds, 0, 0, 9, 11);

    for (const wchar_t *scan = text; *scan != L'\0'; ++scan, x += 9)
    {
        if (*scan == L' ' || *scan == L'/')
            continue;

        RectBounds destinationBounds;
        InitRectBounds(&destinationBounds, x, y, x + 9, y + 11);

        const int glyphIndex = static_cast<int>(*scan) + (glyphRow * 10) - 47;
        RenderTileFrame(m_numberGlyphs, glyphIndex, &sourceBounds, &destinationBounds, true);
    }
}
```

#### `0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket.md`

```cpp
bool OldUserStatusPane::ApplyLegacyPositionPacket(const unsigned char *packet)
{
    const int x = ReadPacketInt16BE(packet + 1);
    const int y = ReadPacketInt16BE(packet + 3);

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(12);
    }

    return false;
}
```

#### `0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md`

```cpp
bool OldUserStatusPane::ApplyLegacyMovementStep(const unsigned char *packet)
{
    signed char direction = static_cast<signed char>(packet[1]);
    int x = ReadPacketInt16BE(packet + 2);
    int y = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pGameConfig, direction))
        direction &= 0x7f;

    if (direction == 4)
        return false;

    RectBounds movementBounds;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);

    switch (direction)
    {
    case 0:
        --y;
        if (y < movementBounds.top)
            y = movementBounds.top;
        break;
    case 1:
        ++x;
        if (x >= movementBounds.right)
            x = movementBounds.right - 1;
        break;
    case 2:
        ++y;
        if (y >= movementBounds.bottom)
            y = movementBounds.bottom - 1;
        break;
    case 3:
        --x;
        if (x < movementBounds.left)
            x = movementBounds.left;
        break;
    default:
        break;
    }

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(12);
    }

    return false;
}
```

#### `0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md`

```cpp
bool OldUserStatusPane::ApplyLegacyMovementStepAlt(const unsigned char *packet)
{
    signed char direction = static_cast<signed char>(packet[1]);
    int x = ReadPacketInt16BE(packet + 2);
    int y = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pGameConfig, direction))
        direction &= 0x7f;

    if (direction == 4)
        return false;

    RectBounds movementBounds;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);

    switch (direction)
    {
    case 0:
        --y;
        if (y < movementBounds.top)
            y = movementBounds.top;
        break;
    case 1:
        ++x;
        if (x >= movementBounds.right)
            x = movementBounds.right - 1;
        break;
    case 2:
        ++y;
        if (y >= movementBounds.bottom)
            y = movementBounds.bottom - 1;
        break;
    case 3:
        --x;
        if (x < movementBounds.left)
            x = movementBounds.left;
        break;
    default:
        break;
    }

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(12);
    }

    return false;
}
```

#### `0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md`

```cpp
void OldUserStatusPane::ApplyLegacyStatusPayload(const unsigned char *packet)
{
    const unsigned char flags = packet[1];

    if ((flags & 0x40) != 0)
    {
        const int nationId = ReadPacketInt16BE(packet + 2);
        if (m_nationId != nationId)
        {
            m_nationId = nationId;
            InvalidateStatusFieldRect(1);
        }

        signed char spiritId = static_cast<signed char>(packet[4]);
        if (spiritId < -1)
            spiritId = -1;
        if (spiritId > 3)
            spiritId = 3;

        if (m_spiritId != spiritId)
        {
            m_spiritId = spiritId;
            InvalidateStatusFieldRect(2);

            if (g_pTotemFrame != NULL)
                g_pTotemFrame->InvalidateFrame();
            else
                g_pTotemFrame = new TotemFrame();
        }

        if (m_classId != packet[6])
        {
            m_classId = packet[6];
            InvalidateStatusFieldRect(4);
        }

        const unsigned int primaryValue = ReadPacketUInt32BE(packet + 7);
        const unsigned int primaryMaximum = ReadPacketUInt32BE(packet + 11);
        if (m_primaryValue != primaryValue)
        {
            m_primaryValue = primaryValue;
            InvalidateStatusFieldRect(8);
        }
        if (m_primaryMaximum != primaryMaximum)
        {
            m_primaryMaximum = primaryMaximum;
            InvalidateStatusFieldRect(9);
        }

        if (m_attributeLeft != packet[15])
        {
            m_attributeLeft = packet[15];
            InvalidateStatusFieldRect(5);
        }
        if (m_attributeRight != packet[16])
        {
            m_attributeRight = packet[16];
            InvalidateStatusFieldRect(7);
        }
        if (m_attributeCenter != packet[19])
        {
            m_attributeCenter = packet[19];
            InvalidateStatusFieldRect(6);
        }
    }

    if ((flags & 0x20) != 0)
    {
        const unsigned int secondaryValue = ReadPacketUInt32BE(packet + 2);
        const unsigned int secondaryMaximum = ReadPacketUInt32BE(packet + 6);
        if (m_secondaryValue != secondaryValue)
        {
            m_secondaryValue = secondaryValue;
            InvalidateStatusFieldRect(8);
        }
        if (m_secondaryMaximum != secondaryMaximum)
        {
            m_secondaryMaximum = secondaryMaximum;
            InvalidateStatusFieldRect(9);
        }
    }

    if ((flags & 0x10) != 0)
    {
        const unsigned int tertiaryValue = ReadPacketUInt32BE(packet + 2);
        const unsigned int tertiaryMaximum = ReadPacketUInt32BE(packet + 6);
        if (m_tertiaryValue != tertiaryValue)
        {
            m_tertiaryValue = tertiaryValue;
            InvalidateStatusFieldRect(10);
        }
        if (m_tertiaryMaximum != tertiaryMaximum)
        {
            m_tertiaryMaximum = tertiaryMaximum;
            InvalidateStatusFieldRect(11);
        }
    }
}
```

Payload C++ caveat for supervisor validation: this is intentionally first-draft, source-shaped code. The report evidence supports the flag families and rectangle invalidations, but final audit should recheck packet cursor advancement and exact old-status row names before scoring any payload child above `95/95`. This caveat is not a blocker to creating the child or entering the formal first-draft block.

## Validators Expected After Implementation

Report-only phase: no validators run and no leases used.

Implementation callback should run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001NR-OldUserStatusPane-source-quality-removed.md](0001NR-OldUserStatusPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If generated output freshness is required before supervisor verification, add `--wait-generated` to the final scoped parent/support validator command and compare generated `validator-command-id` / `validator-refreshed-at` with validator output. If new child UIDs are needed for parent/support links, create and validate the children first, then update parent/support docs using the validator-assigned UIDs, then rerun parent/support validators.

## Implementation Tracking Checklist

- [x] Update [UID:0001NR] target metadata to `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009U`. Proof: applied in `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md`; clean rerun `000000004892` at `2026-06-28T01:37:31-04:00`, exit `0`, `ok: 1`.
- [x] Replace [UID:0001NR] formal C++ blank marker with an aggregate-only `[[CHILDREN]]` block. Do not paste any child method/helper body into the aggregate. Proof: aggregate formal C++ now contains only `[[CHILDREN]]`; child bodies live only on [UID:000495]-[UID:00049B].
- [x] Replace [UID:0001NR] Item Summary with the current MCP-backed summary supplied above. Proof: target Item Summary now states the OldUserStatusPane aggregate, raw wrapper/helper island, alignment/jump-table/tail boundaries, singleton lifecycle, source route through `UserStatusPane`, and child-only body emission.
- [x] Add [UID:0001NR] covered-range rows for the omitted raw invalidate wrapper, retained packet helper bodies, jump tables, and alignment ranges exactly as listed in this report. Proof: target `Covered Ranges` includes the parent methods, padding, [UID:000495]-[UID:00049B] children, internal jump-table rows, and tail-alignment row.
- [x] Add [UID:0001NR] behavior/field/packet/source-facing-name details from this report without compressing them to a short summary. Proof: target now has behavior/source-name, field/packet layout, source-split, alignment/tail, stale-output, and child-emission sections preserving the report details.
- [x] Add [UID:0001NR] negative evidence and rejected alternatives: no entry xrefs for raw helpers, old simroot constructor text stale, shared tail not owned by OldUserStatusPane, MenuVariety rejected. Proof: target `Evidence And Rejected Alternatives` records each item and the score/C++ disposition.
- [x] Create `by-memory/0x005bf110-0x005bf14b.OldUserStatusPaneInvalidateStatusFieldRect.md` with validator-created UID, metadata `88/91`, owner [UID:00009U], reconstructable TRUE, emitter [UID:0001NR], no-entry evidence, and the exact formal C++ block in this report. Proof: validator assigned [UID:000495] with command `000000004879`; clean post-UID rerun `000000004906` at `2026-06-28T01:41:01-04:00`, exit `0`, `ok: 1`.
- [x] Create `by-memory/0x005bf150-0x005bf3b0.OldUserStatusPaneStatusFieldRectLookup.md` with validator-created UID, metadata `90/92`, owner [UID:00009U], reconstructable TRUE, emitter [UID:0001NR], switch/jump-table ownership notes, and the exact formal C++ block in this report. Proof: validator assigned [UID:000496] with command `000000004880`; clean post-UID rerun `000000004908` at `2026-06-28T01:41:06-04:00`, exit `0`, `ok: 1`.
- [x] Create `by-memory/0x005bf3b0-0x005bf481.OldUserStatusPaneDrawNumberGlyphString.md` with validator-created UID, metadata `88/91`, owner [UID:00009U], reconstructable TRUE, emitter [UID:0001NR], paint-call/glyph-table evidence, and the exact formal C++ block in this report. Proof: validator assigned [UID:000497] with command `000000004881`; clean post-UID rerun `000000004909` at `2026-06-28T01:41:12-04:00`, exit `0`, `ok: 1`.
- [x] Create `by-memory/0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket.md` with validator-created UID, metadata `86/90`, owner [UID:00009U], reconstructable TRUE, emitter [UID:0001NR], retained no-entry position packet evidence, and the exact formal C++ block in this report. Proof: validator assigned [UID:000498] with command `000000004882`; clean post-UID rerun `000000004910` at `2026-06-28T01:41:18-04:00`, exit `0`, `ok: 1`.
- [x] Create `by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md` with validator-created UID, metadata `86/89`, owner [UID:00009U], reconstructable TRUE, emitter [UID:0001NR], internal jump-table ownership note, and the exact formal C++ block in this report. Proof: validator assigned [UID:000499] with command `000000004883`; clean post-UID rerun `000000004911` at `2026-06-28T01:41:25-04:00`, exit `0`, `ok: 1`.
- [x] Create `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md` with validator-created UID, metadata `86/89`, owner [UID:00009U], reconstructable TRUE, emitter [UID:0001NR], internal jump-table ownership note, and the exact formal C++ block in this report. Proof: validator assigned [UID:00049A] with command `000000004885`; clean post-UID rerun `000000004912` at `2026-06-28T01:41:32-04:00`, exit `0`, `ok: 1`.
- [x] Create `by-memory/0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md` with validator-created UID, metadata `86/89`, owner [UID:00009U], reconstructable TRUE, emitter [UID:0001NR], router caller/payload/field invalidation evidence, and the exact formal C++ block in this report. Proof: validator assigned [UID:00049B] with command `000000004886`; clean post-UID rerun `000000004913` at `2026-06-28T01:41:41-04:00`, exit `0`, `ok: 1`.
- [x] Do not create standalone source pages for padding ranges `0x005bf10d-0x005bf110`, `0x005bf14b-0x005bf150`, `0x005bf481-0x005bf490`, `0x005bf51a-0x005bf520`, or `0x005bfbc1-0x005bfbd0`; document them as alignment in [UID:0001NR] and only add ignored-ledger rows if the implementation callback/supervisor explicitly requires that. Proof: no standalone files were created for those ranges; target documents them as alignment/padding.
- [x] Do not create standalone source pages for internal table spans `0x005bf374-0x005bf3b0`, `0x005bf660-0x005bf670`, or `0x005bf7b0-0x005bf7c0`; keep them with the adjacent helper child pages. Proof: no standalone table files were created; rows are linked to [UID:000496], [UID:000499], and [UID:00049A].
- [x] Update [UID:00009U] class metadata to `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged. Proof: applied in `by-class/OldUserStatusPane.md`; clean rerun `000000004893` at `2026-06-28T01:37:33-04:00`, exit `0`, `ok: 1`.
- [x] Update [UID:00009U] Method Map with `0x005bf110`, `0x005bf490`, `0x005bf520`, `0x005bf670`, and their alignment/jump-table relationships. Proof: class page method map now lists the new child helpers and routes [UID:000495]-[UID:00049B].
- [x] Update [UID:00009U] field evidence with the source-facing field names and offset roles from this report. Proof: class page field evidence now documents glyph table, display name, nation/spirit/status icon, class/status bytes, bar/value rows, and position fields.
- [x] Update [UID:00009U] class source-shape/declaration notes to include the child helper signatures and explain that body C++ is emitted through exact by-memory children under [UID:0001NR]. Proof: class page child route/signature section names every helper and states body emission is on child pages.
- [x] Add [UID:00009U] declaration-level C++ with `[[CHILDREN]]` so exact by-memory children can carry body emission; do not put method/helper bodies on the class page. Proof: class formal C++ is a declaration shell plus `[[CHILDREN]]`; no method bodies are present there.
- [x] Update [UID:0000P2] Data Caveats/Source-Layout notes to mark the malformed `class_OldUserStatusPane.cpp` constructor text as stale generated pollution and record that active generated output is marker-only/stale. Proof: `by-file/UserStatusPane.md` data/source notes now document stale generated constructor pollution and current child-route state; clean rerun `000000004894` at `2026-06-28T01:37:43-04:00`, exit `0`, `ok: 1`.
- [x] Update [UID:0000P2] to mention that [UID:0001NR] now emits through exact child pages under the aggregate `[[CHILDREN]]` route. Proof: file page source-layout/method-family notes record [UID:0001NR] as aggregate route with exact child pages.
- [x] Leave [UID:0000RV], [UID:0001NS], generated reports, generated C++ files, project-level generated files, manual coverage reports, validator/tool state, IDA DB, and MCP process state untouched unless the supervisor gives a separate callback. Proof: no manual edits were made to [UID:0000RV], [UID:0001NS], generated/project/coverage/tool/IDA/MCP files. Support pages [UID:0002Z3] and [UID:0003JC] were only scoped-validated to repair stale validator registry/path state after diagnostics; no report-content edit was made there.
- [x] Run all scoped validators listed above after implementation and record command, exit code, `ok` count, command id/timestamp, and generated-refresh state. Proof: listed below in `Implementation Callback Results`.
- [x] After child UID assignment, rerun [UID:0001NR], [UID:00009U], and [UID:0000P2] validators if any temporary references were replaced with real child UIDs. Proof: parent/class/file reruns were `000000004892`, `000000004893`, and `000000004894`, all exit `0`, `ok: 1`, after TMP child refs resolved to [UID:000495]-[UID:00049B].
- [x] Supervisor-owned/generated state: do not manually edit generated tracker/coverage reports; let validator refresh them. No explicit manual `-coverage-report.md` row text is requested by this report. Proof: no generated tracker/coverage/manual coverage file was manually edited; generated refresh was invoked only by validator.
- [x] Supervisor-only after verification: execute the report through the validator lifecycle command; B002 should not manually move the report. Proof: report remains in `tools/leaser/Agents/Agent-B002/research/0001NR-OldUserStatusPane-source-quality.md` for supervisor verification and later `execute_report`.

## Implementation Callback Results

- Changed target/support docs:
  - `by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md`
  - `by-class/OldUserStatusPane.md`
  - `by-file/UserStatusPane.md`
  - `by-memory/0x005bf110-0x005bf14b.OldUserStatusPaneInvalidateStatusFieldRect.md` ([UID:000495])
  - `by-memory/0x005bf150-0x005bf3b0.OldUserStatusPaneStatusFieldRectLookup.md` ([UID:000496])
  - `by-memory/0x005bf3b0-0x005bf481.OldUserStatusPaneDrawNumberGlyphString.md` ([UID:000497])
  - `by-memory/0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket.md` ([UID:000498])
  - `by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md` ([UID:000499])
  - `by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md` ([UID:00049A])
  - `by-memory/0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md` ([UID:00049B])
- Support registry validators: `by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md` command `000000004890`, `2026-06-28T01:37:26-04:00`, exit `0`, `ok: 1`, updated stale [UID:0002Z3] path registry; `by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md` command `000000004891`, `2026-06-28T01:37:29-04:00`, exit `0`, `ok: 1`, registered [UID:0003JC]. These were validator-owned registry/link repairs after scoped diagnostics, not content edits.
- Parent/support validators after TMP child refs resolved:
  - `python .\tools\validator.py --mode file --file by-memory\0x005bda40-0x005bfbc1.OldUserStatusPane.md --apply --queue-timeout 240` -> command `000000004892`, `2026-06-28T01:37:31-04:00`, exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\OldUserStatusPane.md --apply --queue-timeout 240` -> command `000000004893`, `2026-06-28T01:37:33-04:00`, exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\UserStatusPane.md --apply --queue-timeout 240` -> command `000000004894`, `2026-06-28T01:37:43-04:00`, exit `0`, `ok: 1`.
- Generated freshness validators:
  - `python .\tools\validator.py --mode file --file by-file\UserStatusPane.md --apply --queue-timeout 240 --wait-generated` -> command `000000004895`, `2026-06-28T01:38:01-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-class\OldUserStatusPane.md --apply --queue-timeout 240 --wait-generated` -> command `000000004896`, `2026-06-28T01:38:46-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- Final child validators after UID assignment:
  - [UID:000495] command `000000004906`, `2026-06-28T01:41:01-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - [UID:000496] command `000000004908`, `2026-06-28T01:41:06-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - [UID:000497] command `000000004909`, `2026-06-28T01:41:12-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - [UID:000498] command `000000004910`, `2026-06-28T01:41:18-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - [UID:000499] command `000000004911`, `2026-06-28T01:41:25-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - [UID:00049A] command `000000004912`, `2026-06-28T01:41:32-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - [UID:00049B] command `000000004913`, `2026-06-28T01:41:41-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
- Generated C++ spot-check: `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` contains [UID:000495]-[UID:00049B] method bodies, including `OldUserStatusPane::InvalidateStatusFieldRect` and `OldUserStatusPane::ApplyLegacyStatusPayload`. Its header currently reports `validator-command-id: 000000004910` / `validator-refreshed-at: 2026-06-28T01:41:18-04:00`, so it is current through the [UID:000498] refresh and contains the later child UIDs/bodies, but the header is older than the final deferred child validators `000000004911`-`000000004913`.
- Lease state: B002 leased the parent/class/file support set, then the new child files, for the edit/validator batches. The first parent/class/file lease window expired during the validator queue; a fresh lease was taken for parent/class/file/support, and child leases were taken before the final child validation loop. `python .\leaser.py B002 unlease` released the active child leases, and a post-release `current_leases.md` check found no remaining `B002` rows.
- Manual coverage/project/generated/tool/IDA/MCP edits: none. Validator was allowed to refresh generated/projected state and registry mappings; B002 did not manually edit those files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001NR-OldUserStatusPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001NR-OldUserStatusPane-source-quality.md","timestamp":"2026-06-28T02:46:13","uid":"0001NR"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001NR-OldUserStatusPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001NR-OldUserStatusPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001NR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
