** TARGET-REPORT-UID:0002LQ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Source-Quality Report: [UID:0002LQ] VoteMenuPaneRawConstructor

Assignment: `B001-goal2-votemenupane-raw-constructor-source-quality-0002LQ-20260617`  
Primary target: [UID:0002LQ] `by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md`  
Report-only scope: no by-* docs, generated reports, source files, IDA DB, generated source, or `by-memory/-coverage-report.md` were edited.

## Executive Recommendation

- Raise [UID:0002LQ] from `82/88` to `86/91`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Change the direct semantic route from file shortcut [UID:0000P6] `VoteMenuPane` to class owner/emitter [UID:0000FX] `VoteMenuPane`; the source root remains [UID:0000P6] `NexusTK/ui/menu/VoteMenuPane.cpp`.
- Keep the exact raw child page. Do not split or merge this range. `0x005558d0-0x00555945` is a complete raw constructor-shaped method and `0x00555945-0x00555950` remains alignment padding before the modeled ordinary destructor.
- Do not populate formal C++ for this target in this pass. The body shape is clear, but final constructor C++ still depends on accepted `Pane::Pane` mode naming, accepted `VoteMenuPane` field declarations, and unresolved caller-side semantics for the constructor-only `+0xfc` dword.
- Update support docs to record the source-facing constructor direction, field names, vtable roles, zero-initialized live bytes for `g_pVoteMenuPane`, and the direct class route.

## Evidence Reviewed

Documentation reviewed:

- Target [UID:0002LQ] `0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md`.
- Support pages [UID:0000FX] `by-class/VoteMenuPane.md`, [UID:0000P6] `by-file/VoteMenuPane.md`, [UID:0001FY] `VoteMenuPaneCore`, [UID:0001WH] `VoteMenuPaneLayout`, [UID:0001Z1] `VoteMenuPaneVtables`, [UID:0001Q0] `g_pVoteMenuPane`, [UID:0000SP] `g_pVoteMenuPane`, [UID:0003CY] `VoteMenuPaneVtableData`, [UID:0002LR]-[UID:0002LZ], [UID:0001G1], and [UID:0001G3].
- Neighbor/source-placement pages [UID:0000C0] `RightButtonMenuPane`, [UID:0000N7] `RightButtonMenuPane`, and [UID:0001EA] `PaneCore`.
- Current `by-memory/-coverage-report.md` rows for [UID:0002LQ], [UID:0001FY], and [UID:0001Q0].

Live IDA MCP session:

- Session: `b003_00018a_ime_comp_20260617`.
- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- `server_health`: image base `0x400000`, auto-analysis ready, Hex-Rays ready.
- `lookup_funcs`: `0x005558d0`, `0x005558f8`, `0x00555913`, and `0x00555945` are still `Not a function`; `0x00555950` is `sub_555950`, size `0x6c`; `0x00544460` is `sub_544460`, size `0x118`.
- Raw `disasm 0x005558d0` shows a no-function constructor-shaped body ending in `retn 8`, followed by `align 10h` and `sub_555950` at `0x00555950`.
- `xrefs_to 0x005558d0` and generic `find code_ref/data_ref 0x005558d0` report no refs.
- `find_bytes D0 58 55 00` reports no little-endian raw-start pointer encodings.
- `xrefs_to 0x0069ba38` reports eight refs: RightButtonMenuPane reads at `0x00554ca5`, `0x00554ee8`, `0x00554f1a`, `0x00554f93`, close-helper read at `0x005552a3`, constructor publish at `0x005558f8`, ordinary destructor clear at `0x0055599d`, and scalar deleting destructor clear at `0x00556374`.
- `xrefs_to`/`find data_ref` for vtable bases report the three expected lifecycle refs each:
  - `0x00622ff8`: `0x00555913`, `0x00555975`, `0x0055634c`.
  - `0x0062304c`: `0x00555919`, `0x0055597b`, `0x00556352`.
  - `0x0062307c`: `0x00555923`, `0x00555985`, `0x0055635c`.
- `get_bytes 0x005558d0 size 0x75` matches the constructor body through `c2 08 00`; `get_bytes 0x00555945 size 0x0b` is eleven `0xcc` bytes.
- `get_bytes 0x0069ba30 size 0x14` reads all zero bytes, so the live IDA data for `0x0069ba38` is `00 00 00 00`, not the stale `0xffffffff` currently present in some support docs.
- `analyze_function 0x00544460`: decompiles as `char *__thiscall sub_544460(char *this, char a2)`, installs Pane vtables, sets visible byte `+0xb4` to `1`, and stores `a2` to Pane mode byte `+0xb5`.
- `analyze_function 0x005559c0`: event type `0` updates highlighted row, event type `1` begins press/capture inside bounds or dismisses outside, event type `3` releases/clicks; row `0` calls submit helper with flag `1`, row `1` calls submit helper with flag `0`.
- `analyze_function 0x00556100`: sends opcode `0x46`, submode `0`, target-name bytes, and the promote/demote flag through `dword_67A7EC`.
- `search_text "0FCh" 0x005558d0-0x005563cd`: only hit is `0x00555904 mov [esi+0FCh], eax`, proving `+0xfc` is constructor-only within the documented VoteMenuPane island.

## Range, Reachability, And Raw Constructor Treatment

The raw constructor should remain an exact reconstructable child method:

- Start: `0x005558d0`, not modeled by IDA as a function.
- End: `0x00555945`, immediately after `retn 8` at `0x00555942`.
- Internal shape: normal `thiscall` constructor body with `ecx` as `this`, two stack arguments, and a `retn 8` epilogue.
- Successor boundary: `0x00555945-0x00555950` is eleven `0xcc` bytes; `0x00555950` starts the modeled ordinary destructor.

No direct caller exists in the current IDA graph and no raw pointer encoding was found for `0x005558d0`. That should not demote this to unknown/unreconstructable: the body is anchored by a complete constructor shape, the matching ordinary and scalar deleting destructors clear the singleton and restore the same vtables, and the vtable bases are only installed/restored across this constructor/destructor lifecycle.

The best liveness wording is: "raw constructor-shaped method with no direct static caller recovered; retained as source constructor evidence through vtable/global lifecycle and neighboring class layout."

## Source-Facing Names And Types

Recommended source-facing constructor direction:

- Method: `VoteMenuPane::VoteMenuPane`.
- Best signature direction: `VoteMenuPane::VoteMenuPane(int voteType, const wchar_t *targetName)`.
- Argument order is strong:
  - `[ebp+8]` is stored at `this + 0xfc`.
  - `[ebp+0xc]` is passed to `_wcscpy_s` as the source wide string.
- First-argument name is medium-high confidence, not final. `voteType` is the best compact name because current docs already use it and the field is a persisted constructor dword, but no direct caller or later read proves a narrower enum such as clan/group vote type, ballot type, or menu-source context.
- Second-argument name is high confidence: `targetName`.
- Base call: `sub_544460(this, 1)` is `Pane::Pane(mode=1)`, not `Pane::Pane(true)`. Live decompile shows the argument is copied to Pane mode byte `+0xb5`; visible byte `+0xb4` is independently set to `1` in the base constructor.

Recommended field/global names:

| Offset / address | Recommended source-facing name | Type direction | Evidence |
| --- | --- | --- | --- |
| `this + 0xf8` | `m_voteRowPressed` | `bool` or `uint8_t` storage | Constructor clears it. Mouse-down inside bounds sets it to `1`. Mouse-up clears the two-byte state word. OnPaint uses it to swap highlight colors. |
| `this + 0xf9` | `m_highlightedVoteRow` | `int8_t`/signed row byte with `-1` sentinel | Constructor writes `0xff`. Hover stores hit-test result. OnPaint reads it to choose row highlight. |
| `this + 0xfc` | `m_voteType` | `int`/`uint32_t` pending caller proof | Constructor stores first argument. Live scan found no other use in `0x005558d0-0x005563cd`. |
| `this + 0x100` | `m_targetName` | `wchar_t[0x21]` | Constructor calls `_wcscpy_s(this+0x100, 0x21, targetName)`. |
| `0x0069ba38` | `g_pVoteMenuPane` | `VoteMenuPane *` | Constructor publishes this pointer; ordinary and scalar destructors clear; RightButtonMenuPane checks/dismisses it. Live bytes are zero-initialized. |

The source-facing row constants should be:

- `kPromoteRow = 0`, displayed string `Promote`, submit flag `1`.
- `kDemoteRow = 1`, displayed string `Demote`, submit flag `0`.
- `kNoVoteRow = -1`, stored as byte `0xff`.

The target-name capacity is exactly `0x21` wide characters, including the terminator. Do not infer a smaller player-name length from gameplay assumptions on this page.

## Vtable And Subobject Roles

The three constructor vtable installs are validated and should be described as compiler-emitted class layout, not handwritten source assignments:

- `this + 0x00 = 0x00622ff8`: primary `VoteMenuPane`/`Pane` view. Slots include scalar deleting destructor, paint, background, and border.
- `this + 0xa0 = 0x0062304c`: secondary event-handler/input view. Slots include adjusted destructor thunk, mouse event handler, and dismiss callback.
- `this + 0xa4 = 0x0062307c`: tertiary handler/update view. Slots include adjusted destructor thunk and inherited default `0x00544e90` slot.

The `this - 0xa0` adjustments in `OnMouseEvent`, `OnDismiss`, and destructor thunks are multiple-inheritance/interface-view normalization back to the primary object. They are not separate VoteMenuPane-owned embedded objects and should not be modeled as standalone source fields.

## Source Placement And Ownership

Best placement remains `NexusTK/ui/menu/VoteMenuPane.cpp` under [UID:0000P6].

Rejected alternatives:

- `RightButtonMenuPane.cpp`: rejected as direct owner. It reads `g_pVoteMenuPane` and owns the close helper at `0x005552a0`, but the constructor, vtables, strings `Promote`/`Demote`, hit-test, submit helper, destructor, and scalar destructor are VoteMenuPane-specific.
- `BulletinSession`: rejected. Existing generated pollution around hit-test/packet helpers is caller-biased; live IDA shows the two-row VoteMenu hit-test and submit helper are called only from `VoteMenuPane::OnMouseEvent`.
- `Pane.cpp`: rejected. `sub_544460` is only the inherited base constructor; the target installs VoteMenuPane vtables and initializes VoteMenuPane state.
- A generic `PopupMenuControls` file: rejected for this exact target. The SUBWIN rendering helpers are shared, but the object state, singleton, strings, and packet action are vote-popup-specific.

Direct metadata should use [UID:0000FX] `VoteMenuPane` for the method page owner/emitter. The class already clears the strict direct-parent gate and routes to [UID:0000P6] for file/source placement.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best defensible recommendation | Evidence checked | Rejected alternatives | Impact |
| --- | --- | --- | --- | --- |
| Raw-start/no-IDA-function treatment | Keep an exact reconstructable raw constructor child at `0x005558d0-0x00555945`. | `lookup_funcs` says Not a function at raw start/interior/end; raw `disasm` shows complete constructor with `retn 8`; padding and destructor successor verified by `get_bytes`. | Splitting inside the raw body; merging with destructor; demoting to unknown due no direct caller. | Raises target to `86/91`; no split exception needed. |
| Reachability/liveness | Document no direct caller, but keep as live constructor evidence through lifecycle refs. | `xrefs_to`, generic `find code_ref/data_ref`, and `find_bytes D0 58 55 00` found no raw-start refs; vtable/global xrefs tie constructor to destructor and scalar destructor. | "Dead raw code" and "ordinary static function" labels. | Keeps reconstructable true but blocks formal C++ confidence from reaching final. |
| Base constructor identity | `sub_544460` is `Pane::Pane(mode)`, with argument `1` setting Pane mode byte. | `analyze_function 0x00544460` stores `a2` at `this+0xb5`, while visible byte `+0xb4` is set independently. | `Pane(true)` / visibility-flag interpretation. | Final C++ should not use a misleading boolean base argument. |
| Constructor signature | `VoteMenuPane::VoteMenuPane(int voteType, const wchar_t *targetName)` is the best source-facing direction. | Raw disasm stores `[ebp+8]` to `+0xfc` and copies `[ebp+0xc]` to wide target buffer; `retn 8` proves two stack args. | Reversed argument order; `char *` target; no-arg constructor. | Signature is source-quality enough for docs, but first arg remains too semantics-limited for formal C++. |
| `+0xf8` field | `m_voteRowPressed`. | Mouse-down sets byte, mouse-up clears state word, OnPaint uses it for pressed highlight colors. | `m_selected`, because submit selection is row/flag driven and this byte only represents active press state. | Update layout/class docs. |
| `+0xf9` field | `m_highlightedVoteRow`, signed row byte with `-1` sentinel. | Constructor writes `0xff`; hover stores hit-test row; OnPaint reads row to draw highlight. | Boolean selection flag; unsigned-only row without sentinel. | Update layout/class docs and row constants. |
| `+0xfc` field | `m_voteType` as a stored constructor mode/context dword, not a promote/demote row flag. | Live `search_text "0FCh"` found only constructor store inside VoteMenuPane island; submit helper receives promote/demote flag from clicked row. | `m_selectedRow`, `m_targetId`, or promote/demote flag. No evidence supports these. | Main formal-C++ blocker; do not over-name beyond `voteType` until caller-side evidence appears. |
| `+0x100` field | `m_targetName[0x21]`. | `_wcscpy_s` destination `this+0x100`, size `0x21`, source `[ebp+0xc]`. | Narrow `char` buffer; smaller guessed player-name length. | Strong enough for support docs. |
| `g_pVoteMenuPane` | Keep the global name and owner, but fix initial bytes to zero in support docs. | Eight xrefs prove singleton lifecycle; live `get_bytes 0x0069ba30 size 0x14` reads zeros including `0x0069ba38`. | Generated `g_pBulletinSession`; stale `0xffffffff` initialization wording. | Support doc/coverage-row update needed for [UID:0001Q0]. |
| Secondary/tertiary base roles | Treat `+0xa0` and `+0xa4` as inherited interface views, not embedded objects. | Vtable doc, constructor installs, destructor restores, and adjustor thunks subtract `0xa0`/`0xa4`. | Standalone subobject fields requiring source-owned initialization. | Improves layout/source placement confidence. |
| Source file | Keep under `VoteMenuPane.cpp`; direct method owner should be class [UID:0000FX]. | Unique vtables, strings, singleton, destructor lifecycle, OnMouseEvent-only helper callers, and file/class support docs. | RightButtonMenuPane, BulletinSession, Pane, generic popup module. | Recommend metadata owner/emitter change for target. |
| Formal C++ | Leave blank for now. | Body is clear, but `Pane` mode enum/name, field declarations, `g_pVoteMenuPane` declaration bytes, and caller semantics for `+0xfc` are not accepted in source docs yet. | Populating a magic-constant constructor with provisional `voteType` field naming. | Explicit do-not-populate below. |

## First-Draft C++ Recommendation

Do not populate formal `RECONSTRUCTION_CPP` for [UID:0002LQ] in this pass.

The eventual source body should be equivalent to:

- Call the Pane base constructor with mode value `1`.
- Publish `this` to `g_pVoteMenuPane`.
- Clear `m_voteRowPressed`.
- Store constructor argument `voteType` into `m_voteType`.
- Set `m_highlightedVoteRow` to `kNoVoteRow` / `-1`.
- Copy `targetName` into `m_targetName` with capacity `0x21` wide characters.

Blocking evidence for formal C++:

- `0x005558d0` has no direct caller or pointer reference, so caller-side semantic naming for the first dword cannot be recovered from this pass.
- `+0xfc` is constructor-only within `0x005558d0-0x005563cd`; no local consumer proves a narrower type/enum than `voteType`/mode/context.
- The base call is now known to be `Pane::Pane(mode=1)`, but the source enum/constant name for mode `1` is not accepted in the Pane docs.
- The class field names recommended above are source-quality directions, but they are not yet accepted declarations in [UID:0001WH] or [UID:0000FX].

Supervisor should keep the target reconstruction block blank until those declarations are accepted or a caller-side constructor allocation path is recovered.

## Recommended Metadata And Support Updates

Target [UID:0002LQ]:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:0000FX
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000FX
RECONSTRUCTION_CPP: leave blank
```

Support docs to update:

- [UID:0002LQ] target page: add this live IDA evidence, source-facing signature direction, direct class owner, field names, raw-start liveness wording, and explicit formal-C++ hold.
- [UID:0000FX] `VoteMenuPane`: record constructor signature direction, row constants, `m_voteRowPressed`, `m_highlightedVoteRow`, `m_voteType`, `m_targetName[0x21]`, and event row-to-submit-flag mapping.
- [UID:0001WH] `VoteMenuPaneLayout`: refine `+0xf8/+0xf9/+0xfc/+0x100` names and state that `+0xfc` is constructor-only in the current VoteMenuPane island.
- [UID:0001Z1] / [UID:0003CY] vtable docs: no structural change needed; if touched, note that the constructor audit reconfirmed the three install refs and secondary/tertiary interface roles.
- [UID:0000SP] and [UID:0001Q0] `g_pVoteMenuPane`: keep the name/owner, but replace stale `0xffffffff` initial-byte wording with live zero-initialized `00 00 00 00` evidence from `get_bytes 0x0069ba30 size 0x14`.
- [UID:0000P6] file page: no placement change; source root remains `NexusTK/ui/menu/VoteMenuPane.cpp`.

No by-* file was edited by B001.

## Supervisor-Owned Coverage Rows

Replace the current [UID:0002LQ] row under [UID:0001FY] `VoteMenuPaneCore`, between the existing [UID:0001FY] aggregate row and the `0x00555945-0x00555950` padding row:

```text
      - [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md) 0x005558d0-0x00555945 | raw constructor-shaped method | VoteMenuPaneRawConstructor : reconstructable : 86% : strong : B001 2026-06-17 source-quality audit reconfirms IDA still has no function or direct code/data refs at the raw start, but disassembles a complete thiscall VoteMenuPane constructor (`retn 8`) with `Pane::Pane(mode=1)`, `g_pVoteMenuPane` publish, `+0xf8` pressed-state clear, constructor-only `+0xfc` vote-type/context store, three VoteMenuPane vtable installs, `+0xf9` row sentinel `0xff`, `0x21` wchar target-name copy, lifecycle xrefs through ordinary/scalar destructors and vtables, no raw-start pointer-pattern hits, exact `0xcc` padding, and direct class owner [UID:0000FX]; formal C++ remains blank pending accepted Pane mode/field declarations and caller-side `+0xfc` semantics.
```

Replace the current [UID:0001Q0] row under the `.data` globals block, between [UID:0001PZ] `g_pPowerDialog` and [UID:0002AK] `SurfacePresentationTempSurfaceSlot`:

```text
    - [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md) 0x0069ba38-0x0069ba3c | global pointer | g_pVoteMenuPane : reconstructable : 86% : strong : Exact four-byte VoteMenuPane singleton slot; B001 2026-06-17 live IDA `get_bytes` reads zero-initialized `00 00 00 00` at `0x0069ba38` (superseding stale `0xffffffff` wording), with eight live IDA xrefs, raw constructor publish, ordinary/scalar destructor clears, RightButtonMenuPane dismissal/event reads, caller-list caveats, and parent `g_pVoteMenuPane`.
```

No coverage row insertions or deletions are recommended.

## Validation Commands

Representative commands/checks used:

> Executable block R001 was removed from this report and preserved verbatim in [0002LQ-votemenupane-raw-constructor-source-quality-removed.md](0002LQ-votemenupane-raw-constructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA MCP checks:

```text
initialize
idb_list
server_health(database=b003_00018a_ime_comp_20260617)
lookup_funcs(0x005558d0,0x005558f8,0x00555913,0x00555945,0x00555950,0x00544460,0x005559c0,0x00556100)
disasm(0x005558d0, max_instructions=40)
xrefs_to(0x005558d0,0x0069ba38,0x00622ff8,0x0062304c,0x0062307c,0x00544460,0x00555950,0x00556320)
get_bytes(0x005558d0 size 0x75, 0x00555945 size 0x0b, 0x0069ba30 size 0x14, 0x00622ff4 size 0x90)
find_bytes(D0 58 55 00, 50 59 55 00, 20 63 55 00, F8 2F 62 00, 4C 30 62 00, 7C 30 62 00, 38 BA 69 00)
find(code_ref/data_ref, 0x005558d0, 0x00555950, 0x00556320, 0x0069ba38, vtable bases)
analyze_function(0x00544460)
analyze_function(0x005559c0)
analyze_function(0x00556100)
analyze_function(0x005552a0)
search_text("0FCh", start=0x005558d0, end=0x005563cd)
```

## Changed Files, Leases, And Follow-Up

Changed files:

- `tools/leaser/Agents/Agent-B001/research/0002LQ-votemenupane-raw-constructor-source-quality.md`

Leases:

- No by-* edit lease used. This was report-only work in the assigned B001 research folder.

Blockers:

- No blocker for supervisor execution of metadata/coverage/support-doc updates.
- Formal C++ remains blocked for the target for the exact reasons listed in `## First-Draft C++ Recommendation`.

Next useful follow-up:

- Recover or prove absent the caller/allocation path for raw constructor `0x005558d0` to resolve the first dword's exact source semantic.
- Run a Pane mode enum/source-quality pass so `Pane(1)` can become a named source constant.
- Apply the `g_pVoteMenuPane` zero-initialization correction across the global and memory docs.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002LQ-votemenupane-raw-constructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002LQ"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002LQ-votemenupane-raw-constructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002LQ-votemenupane-raw-constructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002LQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
