** TARGET-REPORT-UID:0003W9 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003W9 **
# 0003W9 MenuQuestionItemListAddRowNoRouteRaw Source-Routing Research

## Finalized Report / Current Recommendation

- Status: FINISHED.
- Target UID: `0003W9`.
- Target path: `source-3/project-documentation/by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0003W9-MenuQuestionItemListAddRowNoRouteRaw-source-routing.md`.
- Current metadata: `85/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Recommended metadata after implementation: `88/88`, `CANONICAL_OWNER:00007Z`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Current best source-facing role: retained no-route `MenuQuestionItemList::AppendMenuQuestionRow(unsigned char optionId, const wchar_t *label)` / `AddRow` helper. This is a descriptive inferred name, not original-symbol proof.
- Final disposition: assign semantic documentation ownership to [UID:00007Z][MenuQuestionItemList](source-3/project-documentation/by-class/MenuQuestionItemList.md), but keep the page non-reconstructable/non-emitting because no caller, vtable slot, pointer table entry, absolute VA/RVA reference, or runtime route to `0x00550dc0` is currently proven.
- Confidence: high for bytes, helper signature, row layout, ListPane append dependency, sibling parity, and negative static route scans; medium-high for exact original method spelling; intentionally low for liveness.

## Executive Recommendation

The previous "no-owner" state is now too conservative for semantic ownership. The raw body is a thiscall helper bracketed inside the `MenuQuestionItemList` method band, has the normal-list sibling shape, uses `this` as a `ListPane` receiver, builds the same two-byte-prefixed row record consumed by `MenuQuestionItemList::DrawRow`, and is followed by the normal-list selectable-entry probe and live virtual methods. If forced to choose a direct owner, [UID:00007Z] `MenuQuestionItemList` is the only defensible owner.

The previous "non-emitting" state remains correct. Static route evidence is still negative, and the live `MenuQuestionDialog` constructor already inlines equivalent row-record construction and calls `ListPane::AddEntry` directly at `0x0054ebe8` and `0x0054f358`. That makes this body best treated as dead retained source-shaped helper material, not active runtime behavior. Do not set `EMITTER_UIDS` and do not populate formal C++ unless a future route is proven or the project explicitly decides to emit dead retained helper bodies for binary-shape parity.

## Supervisor Active Recheck

- Assignment received 2026-06-19 as B013 report-only Rule 26/route research.
- Direct by-* edits were not permitted and were not made.
- `by-memory/-coverage-report.md` was not edited.
- The target did not require split repair: `0x00550dc0-0x00550e16` is one exact method-shaped body, with confirmed `0xcc` padding before and after.
- The current report supersedes the old "helper ownership/source names are not safe" note with a narrower conclusion: semantic owner is safe enough to document, but liveness/emission is not.

## Evidence Checked

### Documentation Evidence

- `source-3/project-documentation/by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md`.
- [UID:0001FH][NpcMessageAndMenuQuestionDialogs](source-3/project-documentation/by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md).
- [UID:00007Z][MenuQuestionItemList](source-3/project-documentation/by-class/MenuQuestionItemList.md).
- [UID:000080][MenuQuestionItemListLarger](source-3/project-documentation/by-class/MenuQuestionItemListLarger.md).
- [UID:0000LA][MessageDialogs](source-3/project-documentation/by-file/MessageDialogs.md).
- Exact siblings [UID:0003W8], [UID:0003WA], [UID:0003WB], [UID:0003WC], [UID:0003WE], and [UID:0003WF].
- [UID:0003D6][MenuQuestionItemListVtableData](source-3/project-documentation/by-memory/0x00622730-0x006227f4.MenuQuestionItemListVtableData.md).
- [UID:0000KT][ListPane](source-3/project-documentation/by-file/ListPane.md), [UID:00007A][ListPane](source-3/project-documentation/by-class/ListPane.md), [UID:000194][ListPane split index](source-3/project-documentation/by-memory/0x004f3a50-0x004f4a77.ListPane.md), and [UID:0003U0][ListPaneItemSelectionStorageHelpers](source-3/project-documentation/by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md).
- B001 executed source split report `Agent-B001/research/executed/older/0001FH-npc-message-menu-question-source-split.md`.
- Coverage/generated rows in `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`.

### Direct Binary Evidence

- Binary inspected: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- MD5: `4247E04E20B65D6414C7238AA8FF5515`.
- SHA256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- PE sections confirmed:
  - `.text` `0x00401000-0x0060c600`, raw `0x000400+0x20b600`.
  - `.rdata` `0x0060d000-0x0066c200`, raw `0x20ba00+0x05f200`.
  - `.data` `0x0066d000-0x0069ce24`, raw `0x26ac00+0x00d800`.
  - `.rsrc` `0x0069d000-0x006b2e00`, raw `0x278400+0x015e00`.
- Tools used locally: Python PE parser and Capstone 5.0.7 for disassembly and raw route scans.
- No live IDA MCP endpoint was exposed to this session through MCP resources. I treated B001's IDA MCP observations as prior documentation evidence and rechecked the byte/route claims directly against the PE.

## Raw Bytes, Boundaries, And Padding

The target range is an exact `0x56`-byte body:

```asm
00550dc0  push ebp
00550dc1  mov ebp, esp
00550dc3  sub esp, 208h
00550dc9  mov eax, [672f24h]
00550dce  xor eax, ebp
00550dd0  mov [ebp-4], eax
00550dd3  mov edx, [ebp+0Ch]
00550dd6  mov al, [ebp+8]
00550dd9  push esi
00550dda  push edx
00550ddb  mov [ebp-208h], al
00550de1  mov esi, ecx
00550de3  lea eax, [ebp-206h]
00550de9  push 100h
00550dee  push eax
00550def  call 005cd657
00550df4  add esp, 0Ch
00550df7  lea eax, [ebp-208h]
00550dfd  mov ecx, esi
00550dff  push eax
00550e00  call 004f3c50
00550e05  mov ecx, [ebp-4]
00550e08  xor ecx, ebp
00550e0a  pop esi
00550e0b  call 005c772f
00550e10  mov esp, ebp
00550e12  pop ebp
00550e13  ret 8
```

Boundary facts:

- `0x00550db4-0x00550dc0` is twelve `0xcc` bytes after the live [UID:0003W8] constructor.
- `0x00550dc0-0x00550e16` is the complete helper body, including `c2 08 00`.
- `0x00550e16-0x00550e20` is ten `0xcc` bytes before [UID:0003WA].
- [UID:0003WA] begins at `0x00550e20` with `push [ecx+0x134]; call 0x004f3dc0; mov al,[eax]; ret`.

## Behavior And Signature

Best current source-facing signature:

```cpp
// Descriptive only; not original-symbol proof.
void MenuQuestionItemList::AppendMenuQuestionRow(
    unsigned char optionId,
    const wchar_t *label);
```

Behavior:

1. Preserves `this` in `esi`.
2. Builds a local row record at `ebp-0x208`.
3. Writes `optionId` to row offset `+0x00`.
4. Copies the UTF-16 label to row offset `+0x02` with `_wcscpy_s(row.text, 0x100, label)`.
5. Calls `0x004f3c50` with `ecx = this` and `&row` as the only stack argument.
6. Checks the security cookie and returns with `retn 8`.

The stack frame size proves the row payload is `0x208` bytes. The source record shape is best represented as:

```cpp
struct MenuQuestionItemRow {
    unsigned char optionId;
    unsigned char alignmentPadding;
    wchar_t label[0x100];
};
```

The second byte is alignment/padding, not a proven semantic field. The compiler does not explicitly initialize it in this helper, which is consistent with C++ struct padding between an `unsigned char` and a `wchar_t[256]` member.

## Callee / Helper Name Resolution

`sub_4F3C50` should not remain raw in this target. Existing ListPane docs and the local disassembly identify it as the shared ListPane append helper:

- Current best source-facing name: `ListPane::AddEntry` or `ListPane::AppendItem`.
- Preferred project term for now: `ListPane::AddEntry`, because [UID:0000KT] and [UID:00007A] already use that name.
- Signature direction: `void ListPane::AddEntry(const void *entry)`.
- Behavior at `0x004f3c50-0x004f3ca4`: appends one primary-list item at current count, appends a cleared byte to the selection-list mirror, calls scroll/viewport sync `0x0055e990`, then dispatches virtual slot `+0x20` with `this+0x110`.
- Positive control: local rel32 scan found 47 direct call/jump hits to `0x004f3c50`, including active menu-question constructor calls at `0x0054ebe8`, `0x0054f358`, `0x0054fdf8`, `0x00550569`, plus the raw target call at `0x00550e00` and the larger raw sibling call at `0x00550f60`.

`0x005cd657` is `_wcscpy_s` per existing docs and the call contract `(destination, 0x100, source)`. The active constructors call the same copy helper when staging menu-question row labels.

## Route / Liveness Recheck

Raw static route scans against the PE found no inbound route to the target:

| Target | rel32 call/jump hits | absolute VA hits | absolute RVA hits | Interpretation |
| --- | ---: | ---: | ---: | --- |
| `0x00550dc0` | 0 | 0 | 0 | No proven route to normal add-row raw helper. |
| `0x00550e20` | 0 | 0 | 0 | No proven route to normal selectable-entry probe. |
| `0x00550f20` | 0 | 0 | 0 | No proven route to larger add-row raw sibling. |
| `0x00550f80` | 0 | 0 | 0 | No proven route to larger selectable-entry probe. |

Positive controls in the same pass show the scan would have found ordinary routes:

| Target | Evidence found | Interpretation |
| --- | --- | --- |
| `0x00550d50` | rel32 calls at `0x0054eb04` and `0x0054f276` | Live normal list constructor route from `MenuQuestionDialog`. |
| `0x00550e30` | absolute VA in `.rdata` at VA `0x006227b0` | Live vtable slot for normal selection delegator. |
| `0x00550e40` | absolute VA in `.rdata` at VA `0x006227b4` | Live vtable slot for normal row draw override. |
| `0x00550ed0` | rel32 calls at `0x0054fd14` and `0x00550489` | Live larger list constructor route from `MenuQuestionDialogLarger`. |
| `0x00550f90` | absolute VA in `.rdata` at VA `0x00622874` | Live larger selection delegator vtable route. |
| `0x00550fa0` | absolute VA in `.rdata` at VA `0x00622878` | Live larger draw override vtable route. |
| `0x004f3c50` | 47 rel32 hits | Shared `ListPane::AddEntry` is heavily live. |
| `0x004f3dc0` | 98 rel32 hits | Shared `ListPane::GetSelectedEntry` is heavily live. |

This is strong negative evidence for static reachability. It is not absolute proof that no runtime path could ever reach the bytes through a computed address, but there is no table, vtable, direct call, or immediate-pointer surface currently known.

## Active Constructor Comparison

The live `MenuQuestionDialog` and `MenuQuestionDialogLarger` constructors build the same row shape inline instead of calling `0x00550dc0` / `0x00550f20`.

Normal constructor active row append windows:

- `0x0054ebe8`: builds a row at a stack local, writes an incremented option id byte at row offset `+0`, copies label text to row offset `+2` with `_wcscpy_s(..., 0x100, ...)`, then calls `0x004f3c50`.
- `0x0054f358`: repeats the same row staging and `ListPane::AddEntry` call for the alternate normal layout/list.

Larger constructor active row append windows:

- `0x0054fdf8`: same staging and append pattern in the larger constructor.
- `0x00550569`: same staging and append pattern for the larger alternate list.

This comparison is the key reason emission remains blocked. The raw helper is not needed for the live constructor behavior as currently compiled; it is equivalent retained helper material with no inbound edge.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best supported direction | Rejected alternatives | Impact |
| --- | --- | --- | --- | --- |
| Source-facing helper name | Raw bytes, sibling larger body, active constructor inline row appends, class docs | `MenuQuestionItemList::AppendMenuQuestionRow` / `AddRow` descriptive private helper | Leaving only `sub_550DC0`; generic `ListPane::AddEntry`; packet helper | Name can be documented as inferred; not enough for C++ emission without route. |
| Signature | `retn 8`, `ecx` receiver, `[ebp+8]` byte, `[ebp+0xc]` pointer, `_wcscpy_s` contract | `void __thiscall(MenuQuestionItemList *, unsigned char optionId, const wchar_t *label)` | `int` return, `wchar_t*` receiver, static free helper, `char*` label | Signature is high confidence. |
| Row fields | Stack local size `0x208`, write at `+0`, `_wcscpy_s` destination at `+2`, draw methods read `itemData+2` | `optionId` at `+0`, alignment byte at `+1`, UTF-16 `label[0x100]` at `+2` | Treating `+1` as a meaningful flag; treating text as offset `+1` or heap pointer | Strong enough for target/support docs. |
| `sub_4F3C50` identity | ListPane docs, disassembly, call fanout, same `this+0x130/+0x138` state | `ListPane::AddEntry` / append-item helper | Feature-owned chat/article helper; menu-question-only helper | Replace raw name in target with source-facing ListPane dependency. |
| Semantic owner | Address locality, `this` type, sibling method band, row renderer consumption, MenuQuestionItemList vtable docs | [UID:00007Z] `MenuQuestionItemList` | `MessageDialogs` file direct owner, generic `ListPane`, `MenuQuestionDialog`, `NONE` | Recommend `CANONICAL_OWNER:00007Z` despite no emitter. |
| Reconstructable/emitting state | No inbound route; positive controls find live constructor/vtable refs; active constructors inline behavior | Keep `RECONSTRUCTABLE:FALSE`, blank emitters/C++ | Emit as live method; mark ignored padding; delete row | Non-emitting no-code proof remains valid. |
| Dead retained vs missed route | No rel32/VA/RVA hits; no vtable slot; no IDA function per prior B001; active constructor equivalent inline paths | Best current classification: dead retained source-shaped helper or unused out-of-line helper retained by linker | Missed vtable/callback route; compiler-generated thunk; switch data | Liveness caveat caps confidence and blocks C++ emission. |
| Sibling parity | `0x00550f20-0x00550f76` is byte-shape clone for larger list; no route to either | Normal/larger pair likely came from parallel private helper definitions | Isolated accidental code; one helper belongs to normal class and the other to ListPane | Supports class semantic owner, but not route. |
| Support-doc stale issue | Class/file docs say raw helper ownership/source names are not safe | Update to "semantic owner inferred, liveness/emission unsafe" | Keep generic blocker text | Rule 27 open-question closure. |

## Ranked Ownership Analysis

### 1. [UID:00007Z] `MenuQuestionItemList`

Evidence for:

- Target is immediately after [UID:0003W8] normal list constructor and before normal-list raw probe/virtual methods.
- Body is a thiscall helper over a `ListPane` receiver, not a free packet helper.
- It builds the exact row consumed by [UID:0003WC] at `itemData+2`.
- It mirrors the larger class helper at `0x00550f20`.
- The normal class parent clears `85/87`, source-routes through [UID:0000LA] `MessageDialogs`, and owns the adjacent live constructor/selection/draw methods.

Evidence against:

- No inbound route to this exact start.
- No vtable slot or direct constructor call uses this helper.
- Existing active constructors inline equivalent row append logic.

Decision: accept as semantic documentation owner only. Do not emit.

### 2. [UID:0000LA] `MessageDialogs`

Evidence for:

- The entire menu-question family routes through `MessageDialogs.cpp`.
- The raw helper is source-family local.

Evidence against:

- By-structure direct-owner rules prefer the narrowest true owner. This is a class-private list helper, not a file-level free function.

Decision: reject as direct canonical owner; keep as source-file context in support docs.

### 3. [UID:00007A] / [UID:0000KT] `ListPane`

Evidence for:

- Target calls `ListPane::AddEntry`.
- Receiver is ListPane-derived and uses `ListPane` storage.

Evidence against:

- The row layout is menu-question-specific, with an option id plus UTF-16 label consumed only by menu-question draw/selection paths.
- `ListPane::AddEntry` is a dependency, not the source owner of the row-building helper.

Decision: reject as owner; document as callee/dependency.

### 4. `CANONICAL_OWNER:NONE`

Evidence for:

- No liveness route, no IDA function, and no original symbol.

Evidence against:

- Semantic owner is now high-probability and narrow.
- Leaving owner `NONE` conflates "no runtime route" with "no class/source identity."

Decision: reject as final metadata. Keep non-emitting, but assign `CANONICAL_OWNER:00007Z`.

## Exact No-Code Proof

Formal C++ should stay blank because all of the following are true:

1. No rel32 `E8`/`E9` or `0F 8x` branch target to `0x00550dc0` exists in `.text`.
2. No little-endian absolute VA `0x00550dc0` or RVA `0x00150dc0` exists in the PE.
3. Positive-control route scans find nearby live constructor calls and vtable slots, so the negative result is meaningful.
4. Existing B001 IDA MCP evidence reports no IDA function object and no `xrefs_to` route to the start.
5. The active `MenuQuestionDialog` constructor appends menu-question rows inline through `ListPane::AddEntry` at `0x0054ebe8` and `0x0054f358`; it does not call this helper.
6. Emitting a source method now would add a dead retained function with no proven source-use surface and could mislead future source reconstruction into calling a helper the original live constructors did not call.

Reference-only C++ shape if a future route is proven:

```cpp
void MenuQuestionItemList::AppendMenuQuestionRow(
    unsigned char optionId,
    const wchar_t *label)
{
    MenuQuestionItemRow row;

    row.optionId = optionId;
    wcscpy_s(row.label, _countof(row.label), label);
    AddEntry(&row);
}
```

Do not place this in the formal `RECONSTRUCTION_CPP CODE` block during the current implementation callback unless the supervisor explicitly changes the dead-retained helper policy.

## Recommended Exact Target Changes

For `source-3/project-documentation/by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md`:

1. Change metadata:
   - `COMPLETION:85` to `COMPLETION:88`.
   - `CONFIDENCE:86` to `CONFIDENCE:88`.
   - `CANONICAL_OWNER:NONE` to `CANONICAL_OWNER:00007Z`.
   - Keep `RECONSTRUCTABLE:FALSE`.
   - Keep `EMITTER_UIDS:` blank.
   - Keep formal C++ blank.
2. Update Status:
   - Entity kind: retained no-route source-shaped class helper.
   - Owner: [UID:00007Z] `MenuQuestionItemList` as semantic owner only.
   - Rebuild handling: non-emitting retained raw evidence; not active reconstructable output.
3. Add signature section:
   - `void __thiscall MenuQuestionItemList::AppendMenuQuestionRow(unsigned char optionId, const wchar_t *label)` as inferred/descriptive.
   - Note `ret 8` and `ecx` receiver.
4. Add row layout section:
   - `+0x00 unsigned char optionId`.
   - `+0x01 alignment/padding`.
   - `+0x02 wchar_t label[0x100]`.
   - Total stack row size `0x208`.
5. Replace `sub_4F3C50` wording with `ListPane::AddEntry` / append item helper at `0x004f3c50`.
6. Add exact raw disassembly/byte evidence summarized above.
7. Add route section with negative scan results and positive controls.
8. Add active-constructor comparison:
   - `0x0054ebe8` and `0x0054f358` call `ListPane::AddEntry` after inline row staging.
   - larger parity `0x0054fdf8` and `0x00550569`.
9. Add rejected alternatives:
   - not padding, not compiler thunk, not generic ListPane owner, not live vtable method, not packet helper, not enough to emit.
10. Add no-code proof and reference-only C++ sketch as non-formal evidence.

## Recommended Support-Doc Changes

### `by-class/MenuQuestionItemList.md`

- In `Status`, replace "raw helpers ... are non-emitting because helper ownership/source names are not safe" with:
  - [UID:0003W9] is now semantically owned by `MenuQuestionItemList` as a retained no-route `AppendMenuQuestionRow` / `AddRow` helper, but remains non-reconstructable and non-emitting because no caller/pointer/vtable route reaches `0x00550dc0`.
  - [UID:0003WA] remains a no-route selected-entry probe pending its own route/name pass.
- In `Method Map`, add an "Inactive / retained raw evidence" row:
  - `0x00550dc0-0x00550e16`: `AppendMenuQuestionRow(unsigned char optionId, const wchar_t *label)`; builds `{optionId, padding, wchar_t label[0x100]}` and calls `ListPane::AddEntry`; no inbound route, so not emitted.
- In `State And Dependencies`, add `MenuQuestionItemRow` layout with label at offset `+2`.
- Add evidence that active constructors inline equivalent appends at `0x0054ebe8` and `0x0054f358`.

### `by-file/MessageDialogs.md`

- In the `MenuQuestionItemList` proposed contents row, replace the stale broad raw-helper caveat with:
  - [UID:0003W9] now has semantic class owner [UID:00007Z] but no emitter; route scans remain negative, and active constructors inline the append logic.
- Keep [UID:0001FH] as non-emitting split index and keep `MessageDialogs.cpp` as source family.

### `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`

- In the split table row for `0x00550dc0-0x00550e16`, change owner/role wording to:
  - `Semantic owner [UID:00007Z] MenuQuestionItemList; retained no-route append-row helper; non-emitting.`
- Add a note that the row is not ownerless anymore, but still not emitted because liveness is unproven.

### `by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md`

- Do not change as part of this assignment unless the supervisor includes it in the implementation callback.
- Recommended future matching review: likely semantic owner [UID:000080] `MenuQuestionItemListLarger`, same non-emitting retained-helper disposition.

### `by-file/ListPane.md`, `by-class/ListPane.md`, and [UID:0003U0]

- No required metadata changes.
- Optional cross-reference if touched later: note `0x00550dc0` as another no-route class helper that calls `ListPane::AddEntry`; this is evidence of dependency fanout, not ListPane ownership.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` during this report pass. If the supervisor accepts this report, replace the existing [UID:0003W9] child row with:

```text
        - [UID:0003W9][0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw](by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md) 0x00550dc0-0x00550e16 | no-route retained raw class helper | MenuQuestionItemListAddRowNoRouteRaw : ignored/non-emitting : 88% : strong : B013 2026-06-19 source-routing pass resolves semantic owner as [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md) but keeps the range non-reconstructable and non-emitting: exact `0x56`-byte thiscall helper with stack cookie, signature `AppendMenuQuestionRow(unsigned char optionId, const wchar_t *label)`, `MenuQuestionItemRow` layout `{ optionId at +0, alignment byte at +1, UTF-16 label[0x100] at +2 }`, `_wcscpy_s(row.label, 0x100, label)`, shared [UID:00007A][ListPane](by-class/ListPane.md) append dependency `0x004f3c50` / `ListPane::AddEntry`, `retn 8`, surrounding `0xcc` padding, no rel32/VA/RVA route to `0x00550dc0`, positive-control hits for neighboring live constructor/vtable targets, and active constructor inline equivalents at `0x0054ebe8` and `0x0054f358`; formal C++ stays blank unless a caller/pointer/vtable/runtime route is later proven or the project explicitly emits dead retained helpers.
```

No `by-class/-coverage-report.md` change is required unless the supervisor wants to mention the owner-resolution caveat in the `MenuQuestionItemList` class row. If so, append a short clause to the current [UID:00007Z] row rather than replacing the whole row:

```text
; B013 2026-06-19 additionally resolves raw add-row helper [UID:0003W9] as semantically class-owned but non-emitting because no inbound route exists and constructors inline the append behavior.
```

## Score Rationale

Recommended score change: `85/86 -> 88/88`.

- Completion rises because the target page can now document exact raw disassembly, function-shaped signature, stack row layout, safe-copy contract, callee name, route scan results, positive controls, active-constructor comparison, owner alternatives, rejected alternatives, and exact no-code proof.
- Confidence rises because the raw PE recheck independently confirms B001's no-route conclusion and the semantic class owner is strongly supported by row layout, adjacency, sibling parity, and consumer draw behavior.
- Confidence remains below final-audit quality because no original symbol was recovered, no IDA function object is known, no liveness route is proven, and exact original source spelling remains inferred.

## Validation Commands Needed After Implementation

Run from `source-3/project-documentation` after applying accepted target/support changes:

> Executable block R001 was removed from this report and preserved verbatim in [0003W9-MenuQuestionItemListAddRowNoRouteRaw-source-routing-removed.md](0003W9-MenuQuestionItemListAddRowNoRouteRaw-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Report-pass validation already run:

> Executable block R002 was removed from this report and preserved verbatim in [0003W9-MenuQuestionItemListAddRowNoRouteRaw-source-routing-removed.md](0003W9-MenuQuestionItemListAddRowNoRouteRaw-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Result: `ok: 1`; dry run only, no edits.

## IDA Rename / Type / Comment Recommendations

If an IDA implementation pass is later performed:

- Do not create an ordinary live function solely to force xrefs. If a manual function is created for documentation, mark it as retained/no-route.
- Name/comment `0x00550dc0` as `MenuQuestionItemList::AppendMenuQuestionRow_NoRoute` or `MenuQuestionItemList_AppendMenuQuestionRow_retained_550DC0`.
- Type if represented: `void __thiscall(MenuQuestionItemList *this, unsigned char optionId, const wchar_t *label)`.
- Add a repeatable comment at `0x00550e00`: `calls ListPane::AddEntry(&MenuQuestionItemRow); no inbound route to helper start found`.
- Rename/comment `0x004f3c50` consistently as `ListPane::AddEntry` / `AppendItem`; do not leave `sub_4F3C50` in source-facing docs.
- Comment row type: `MenuQuestionItemRow { unsigned char optionId; /* pad */ wchar_t label[256]; }`.

Confidence:

- High for type/signature and ListPane dependency.
- Medium-high for source-facing spelling.
- High for "no current inbound route" as a static evidence statement.

## Implementation Callback Checklist

If the supervisor accepts this report, send B013 a callback with these exact actions:

1. Lease and update only accepted target/support docs; do not edit `by-memory/-coverage-report.md`.
2. Update [UID:0003W9] metadata to `88/88`, `CANONICAL_OWNER:00007Z`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++.
3. Expand [UID:0003W9] at report-level factual detail: raw disassembly, helper signature, row layout, `ListPane::AddEntry` callee, exact padding, route scan negative results, positive controls, active-constructor inline equivalents, ownership ranking, rejected alternatives, score rationale, no-code proof, and reference-only C++ sketch.
4. Update [UID:00007Z] `MenuQuestionItemList` to include [UID:0003W9] as semantically class-owned retained raw helper and to preserve the non-emitting route caveat.
5. Update [UID:0000LA] `MessageDialogs` and [UID:0001FH] split index so their raw-helper language no longer says helper ownership/source names are unsafe for [UID:0003W9]; replace with "semantic owner resolved, liveness/emission unresolved."
6. Preserve historical B001 no-route evidence as still valid, but mark the stale no-owner conclusion as superseded for semantic ownership only.
7. Run the validation commands listed above and report exact results.
8. Provide the exact pending `by-memory/-coverage-report.md` replacement row back to the supervisor; do not edit the shared report directly.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0003W9-MenuQuestionItemListAddRowNoRouteRaw-source-routing.md`.
- Modified by this report pass: none outside the B013 research folder.
- Target/support docs edited: none.
- Coverage edited: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003W9","source_path":"executed-b-agent-research/B013/0003W9-MenuQuestionItemListAddRowNoRouteRaw-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
