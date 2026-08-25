** TARGET-REPORT-UID:00032S **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00032S BrowserControlPaneOldNonDeletingDestructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: promote [UID:00032S] from a blank raw non-modeled destructor note to the source-bearing ordinary `BrowserControlPaneOld::~BrowserControlPaneOld()` destructor.
- Source shape: first-draft formal C++ should be an empty destructor body. The observed vtable restores, `MSGHandler` teardown, and pane-family base teardown are compiler lowering for base/subobject destruction, not handwritten statements.
- Target metadata recommendation: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000016`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000016`, blank `EMITTER_POSITION_OPTIONAL`.
- Score change: `85/86 -> 88/90`.
- Support recommendation: update `BrowserControlPaneOld` docs to resolve the previous `MSGHandler` spelling/layout blocker as a secondary base at `this+0x108`; update scalar wrapper [UID:00032X] as no-code MSVC deleting-destructor/adjustor glue generated from this ordinary destructor.
- Coverage-report action: do not edit `by-memory/-coverage-report.md` directly. Exact replacement rows are included below.
- Confidence: strong to very strong for target behavior, range, source ownership, destructor source form, and scalar-wrapper contrast. Remaining uncertainty is class-wide source-file split and some non-destructor helper names; those do not block [UID:00032S].

## Target

- Target UID: `00032S`
- Target name: `BrowserControlPaneOldNonDeletingDestructor`
- Primary doc: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B011\research\00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality.md`
- Current target metadata: `85/86`, `CANONICAL_OWNER:000016`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000016`, formal C++ blank.
- Current generated route: `auto-generated/NexusTK/browser/Browser.cpp`.
- Direct source owner recommendation: keep [UID:000016] `BrowserControlPaneOld`.

## Supervisor Active Recheck

- The supervisor assigned a B-agent report-only source-quality pass for [UID:00032S].
- No by-* target/support docs were edited.
- No coverage report was edited.
- No leases were needed because this report is inside Agent-B011's own research folder.
- This target does not need a range split. It is a compact ordinary non-deleting destructor body at `0x0046f1e0-0x0046f216`. The nearby scalar deleting destructor and adjustor thunks are already in [UID:00032X] and should be documented as compiler glue, not merged into this source body.

## Evidence Checked

- Required instructions:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B011/goal.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
  - `source-3/project-documentation/by-project-structure/proposed-source-tree.md`
- Target/support docs:
  - [UID:00032S] `by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md`
  - [UID:000016] `by-class/BrowserControlPaneOld.md`
  - [UID:0000HV] `by-file/Browser.md`
  - [UID:0002P3] `by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md`
  - [UID:00032X] `by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md`
  - [UID:0001CO] `by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md`
  - [UID:0001OB] `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
  - [UID:0000ZF] `by-memory/0x0046e5a0-0x004707ff.BrowserOleLegacyAndHelpers.md`
  - [UID:0001CN] `by-memory/0x00528d60-0x00528e55.MSGHandler.md`
  - [UID:00008S] `by-class/MSGHandler.md`
  - [UID:0000LM] `by-file/MSGHandler.md`
  - [UID:000038] `by-class/ControlPane.md`
  - [UID:0000IG] `by-file/ControlPane.md`
  - [UID:00032T] `by-memory/0x0046f220-0x0046f30a.BrowserControlPaneOldDrawStatusOverlay.md`
  - [UID:00032U] `by-memory/0x0046f310-0x0046f378.BrowserControlPaneOldHandleBrowserMessage.md`
  - [UID:0001SL] `by-type/by-enum/BrowserMessageId.md`
  - [UID:0001SM] `by-type/by-struct/BrowserOverlayStyle.md`
  - [UID:0001SK] `by-type/by-struct/BrowserInitFlags.md`
- Generated/project docs:
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-file-coverage.md`
  - `auto-generated/NexusTK/browser/Browser.cpp`
  - `auto-generated/NexusTK/app/MSGHandler.cpp`
- Prior research:
  - [UID:0000ZF] B001 executed split/inventory report under `Agent-B001/research/executed/older/0000ZF-BrowserOleLegacyAndHelpers.md`.
  - [UID:0001CN] B009 current MSGHandler source-quality report under `Agent-B009/research/0001CN-MSGHandler-source-quality.md`.
  - [UID:00032S] had no prior dedicated B-agent source-quality report in the Agent-B research folders.
- IDA MCP:
  - Attempted `tools/list` against `http://127.0.0.1:13337/mcp`.
  - Result: `Unable to connect to the remote server`.
  - Impact: no fresh live IDA function-promotion, xref, or decompiler output was available in this session. I used existing IDA-backed docs plus direct raw PE and Capstone checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Raw PE / Capstone evidence:
  - Parsed PE locally. Image base `0x00400000`; `.text` `0x00401000-0x0060c600`; `.rdata` `0x0060d000-0x0066c200`; `.data` `0x0066d000-0x0069ce24`.
  - Verified raw bytes, exact instruction sequence, boundary padding, vtable dwords, direct absolute references, and direct rel32 caller sets.

## Raw PE / Disassembly Facts

### Boundary Facts

- `0x0046f1d0-0x0046f1db` is the preceding `BrowserThread` delete-if-present wrapper:
  - `test ecx, ecx`
  - `je 0x0046f1da`
  - `mov eax, [ecx]`
  - `push 1`
  - `call dword ptr [eax]`
  - `ret`
- `0x0046f1db-0x0046f1e0` is five bytes of `0xcc` padding.
- [UID:00032S] is exactly `0x0046f1e0-0x0046f216`, length `0x36`.
- `0x0046f216-0x0046f220` is ten bytes of `0xcc` padding before `BrowserControlPaneOldDrawStatusOverlay`.

### Target Body Facts

Raw disassembly of [UID:00032S]:

```asm
0046f1e0  push esi
0046f1e1  mov esi, ecx
0046f1e3  lea ecx, [esi+0x108]
0046f1e9  mov dword ptr [ecx], 0x00613824
0046f1ef  mov dword ptr [esi], 0x00613780
0046f1f5  mov dword ptr [esi+0xa0], 0x006137e8
0046f1ff  mov dword ptr [esi+0xa4], 0x00613818
0046f209  call 0x00528d80
0046f20e  mov ecx, esi
0046f210  pop esi
0046f211  jmp 0x00544580
```

Direct raw reference scan:

- No absolute dword references to `0x0046f1e0` were found.
- No direct rel32 `call` or `jmp` references to `0x0046f1e0` were found.
- The absence of direct inbound refs is expected for this body: the scalar deleting destructor [UID:00032X] duplicates the cleanup sequence instead of calling the ordinary destructor body, and vtables route object deletion through [UID:00032X].

### Constructor Parity

[UID:0002P3] `0x0046ff50-0x00470159.BrowserControlPaneOldConstructor` confirms the same layout:

- Calls `ControlPane` construction through `0x004949e0` with mode/slot argument `8`.
- Calls `MSGHandler::MSGHandler` at `0x00528d60` with `ecx = this+0x108`.
- Stores the four class vtable views:
  - `[this+0x000] = 0x00613780`
  - `[this+0x0a0] = 0x006137e8`
  - `[this+0x0a4] = 0x00613818`
  - `[this+0x108] = 0x00613824`
- Clears and later fills `[this+0x110]` with the allocated `Browser` pointer.
- Allocates a `Browser` object of size `0x234`, installs Browser vtables, initializes Browser fields, constructs its internal member at `+0x230`, then creates/starts `BrowserThread`.

The destructor vtable restores exactly match the constructor-installed most-derived vtables, followed by `MSGHandler` base teardown and pane-family base teardown.

### Scalar Wrapper Parity

[UID:00032X] `0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors` duplicates the same ordinary-destruction sequence and then handles delete flags:

```asm
004704f0  push ebp
004704f1  mov ebp, esp
004704f3  push esi
004704f4  mov esi, ecx
004704f6  lea ecx, [esi+0x108]
004704fc  mov dword ptr [ecx], 0x00613824
00470502  mov dword ptr [esi], 0x00613780
00470508  mov dword ptr [esi+0xa0], 0x006137e8
00470512  mov dword ptr [esi+0xa4], 0x00613818
0047051c  call 0x00528d80
00470521  mov ecx, esi
00470523  call 0x00544580
00470528  mov eax, [ebp+8]
0047052b  test al, 1
0047052d  je 0x00470551
0047052f  test al, 4
00470531  jne 0x00470543
00470533  push esi
00470534  call 0x004f4ac0
00470539  add esp, 4
0047053c  mov eax, esi
00470540  ret 4
00470543  push 0x114
00470548  push esi
00470549  call 0x0041b6a0
0047054e  add esp, 8
00470551  mov eax, esi
00470555  ret 4
00470558  sub ecx, 0x108
0047055e  jmp 0x004704f0
00470563  sub ecx, 0xa0
00470569  jmp 0x004704f0
0047056e  sub ecx, 0xa4
00470574  jmp 0x004704f0
```

This range proves:

- Complete `BrowserControlPaneOld` object size is `0x114`.
- `this+0x108` is a secondary-base view with an adjustor thunk.
- `this+0xa0` and `this+0xa4` are additional inherited ControlPane/Pane-family views with adjustor thunks.
- Optional object free goes through `0x004f4ac0`.
- The guarded/vector-delete path uses size `0x114` through `0x0041b6a0`.
- [UID:00032X] is compiler deleting-destructor and adjustor thunk glue, not an independent source body.

### Vtable Slice Facts

Relevant `.rdata` dwords at `0x00613780-0x00613828`:

```text
0x00613780 -> 0x004704f0   primary scalar deleting destructor
0x00613784 -> 0x004f4b10
0x00613788 -> 0x0041b6c0
...
0x006137c4 -> 0x0046f220   BrowserControlPaneOld::DrawStatusOverlay
...
0x006137e8 -> 0x00470563   adjustor thunk, this -= 0xa0, then scalar wrapper
...
0x00613818 -> 0x0047056e   adjustor thunk, this -= 0xa4, then scalar wrapper
0x00613824 -> 0x00470558   MSGHandler secondary-base deleting thunk, this -= 0x108
0x00613828 -> 0x0046f310   BrowserControlPaneOld message dispatch/handler override
```

Absolute references to vtable constants:

- `0x00613780` at `0x0046f1f1`, `0x0046ffa2`, `0x00470504`.
- `0x006137e8` at `0x0046f1fb`, `0x0046ffac`, `0x0047050e`.
- `0x00613818` at `0x0046f205`, `0x0046ffb6`, `0x00470518`.
- `0x00613824` at `0x0046f1eb`, `0x0046ffc0`, `0x004704fe`.

These references align target destructor, constructor, and scalar wrapper as the same class.

## Heuristic / Inference Reanalysis And Validation

### Source Placement

Best-supported placement is `BrowserControlPaneOld::~BrowserControlPaneOld()` under [UID:000016] `BrowserControlPaneOld`, emitted through [UID:0000HV] `Browser`.

Evidence:

- Constructor, ordinary destructor, scalar wrapper, draw method, and message handler all share the same four vtable views.
- The generated route already places [UID:000016] in `NexusTK/browser/Browser.cpp`.
- Browser old/legacy aggregate [UID:0000ZF] identifies the same Browser-related legacy range and does not propose a separate destructor owner.

Rejected alternatives:

- `MSGHandler` owner: rejected because `0x00528d80` is only the inherited subobject/base destructor called by [UID:00032S], and the target stores BrowserControlPaneOld vtables before that call.
- `ControlPane`/`Pane` owner: rejected because the target stores BrowserControlPaneOld vtables and then tail-chains to inherited pane teardown.
- No-code compiler glue: rejected for [UID:00032S] because it is the ordinary non-deleting destructor body. The compiler glue is [UID:00032X].

### Raw Function / Reachability

The target remains a raw/non-promoted function in the current docs, and no direct raw inbound references to `0x0046f1e0` were found. That is not a source-quality blocker.

Best explanation:

- MSVC emitted a compact ordinary destructor body at `0x0046f1e0`.
- MSVC also emitted a scalar deleting destructor at `0x004704f0` that duplicates the ordinary destruction sequence instead of calling `0x0046f1e0`.
- The primary vtable delete slot points at `0x004704f0`, and secondary vtable delete slots point at adjustor thunks into `0x004704f0`.
- The ordinary body is retained as a separately emitted non-deleting destructor body even though this build's observable delete dispatch does not directly call it.

Implementation should preserve the raw/no-function-object fact as an IDA modeling note only. It should not block source-bearing documentation or first-draft C++.

### `MSGHandler` Subobject Spelling

Best-supported spelling: `BrowserControlPaneOld` inherits `MSGHandler` as a secondary base at `this+0x108`.

Evidence:

- Constructor calls `MSGHandler::MSGHandler` with `ecx = this+0x108`.
- Constructor then overwrites `[this+0x108]` with BrowserControlPaneOld's `MSGHandler` view vtable `0x00613824`.
- Destructor restores `[this+0x108] = 0x00613824` and calls `MSGHandler::~MSGHandler` with `ecx = this+0x108`.
- Scalar wrapper has an adjustor thunk at `0x00470558` that subtracts `0x108` before entering the complete-object deleting destructor.
- Vtable slot `0x00613828` points to BrowserControlPaneOld's message handler/dispatch override.
- B009's MSGHandler report resolves the MSGHandler instance layout as a vptr plus `MSGHandler *m_previousHandler` at subobject offset `+4`. For BrowserControlPaneOld, that saved previous handler is therefore at outer offset `0x10c`.

Rejected alternative: member composition. A composed `MSGHandler m_msgHandler;` could explain constructor/destructor calls, but it does not explain the secondary deleting-destructor adjustor thunk and override vtable at `0x00613824/0x00613828` as cleanly as secondary inheritance. The vtable shape is a secondary-base view.

### Base / Control-Pane Layout

Best-supported partial layout:

```cpp
class BrowserControlPaneOld : public ControlPane, public MSGHandler
{
    // ControlPane / pane-family base views:
    //   +0x000 primary view
    //   +0x0a0 secondary view
    //   +0x0a4 tertiary view
    //
    // MSGHandler secondary base:
    //   +0x108 vptr
    //   +0x10c MSGHandler::m_previousHandler
    //
    Browser *m_browser; // +0x110
};
```

Notes:

- Complete object size is `0x114`.
- `m_browser` at `this+0x110` is confirmed by constructor store and by `BrowserControlPaneOldDrawStatusOverlay`.
- `ControlPane`/pane-family base teardown eventually reaches `0x00544580`, already documented as pane-family base destructor behavior.
- The exact names of inherited ControlPane secondary views can remain support-doc caveats; they do not affect the destructor source body.

### Destructor Source Shape

The source-authored body has no manual cleanup statements visible in the target. The source-level destructor should be:

```cpp
BrowserControlPaneOld::~BrowserControlPaneOld()
{
}
```

Why the body is empty:

- Vtable restores are compiler-generated destructor prologue/lowering.
- `MSGHandler::~MSGHandler()` is automatic base-subobject destruction.
- The tail jump to `0x00544580` is automatic inherited pane-family base destruction.
- Delete-flag handling and memory free are in [UID:00032X], not in the ordinary destructor body.
- The constructor owns allocation of a `Browser` object and a `BrowserThread`, but no corresponding source-authored release appears in this ordinary destructor. If that lifecycle is incomplete, it is a class-wide legacy Browser ownership question, not evidence for hidden target-body statements.

Relevant precedent: [UID:0002FK] `ChattingColorPane::~ChattingColorPane()` is documented with an empty formal C++ body where the machine code only restores vtables and calls inherited base teardown.

### Open Questions And Attempted Resolution

- Raw/non-modeled liveness:
  - Checked absolute and rel32 references to `0x0046f1e0`; found none.
  - Resolution: keep as ordinary source destructor despite no direct refs. The scalar wrapper duplication explains no caller. Recommend IDA function promotion/rename.
- `MSGHandler` field/member spelling:
  - Checked constructor/destructor/scalar/vtable and B009 MSGHandler report.
  - Resolution: `MSGHandler` is a secondary base at `+0x108`; B009's `m_previousHandler` applies at outer `+0x10c`.
- Base/control-pane layout:
  - Checked constructor, destructor, scalar wrapper, ControlPane docs, and vtable constants.
  - Resolution: primary base starts at `+0`; inherited ControlPane/pane views at `+0xa0/+0xa4`; MSGHandler secondary base at `+0x108`; complete object size `0x114`.
- Vtable labels:
  - Checked `.rdata` dwords and vtable store xrefs.
  - Resolution: `0x00613780` primary BrowserControlPaneOld vtable; `0x006137e8` and `0x00613818` inherited ControlPane/pane secondary views; `0x00613824` MSGHandler secondary-base view.
- Source file split:
  - Checked `Browser.md`, Browser legacy aggregate, constructor, and generated route.
  - Resolution: keep `Browser.cpp`/Browser class route for now. An exact historical split into a compatibility file remains unproved but does not block this destructor.
- Helper names:
  - Checked scalar wrapper helpers. `0x004f4ac0` is existing operator-delete wrapper; `0x0041b6a0` is the guarded/vector-delete helper used with object size `0x114`. These are scalar-wrapper-only and should not appear in [UID:00032S] C++.
- Browser object ownership:
  - Checked constructor and draw method. `this+0x110` is best named `m_browser`.
  - Resolution: no Browser release statement exists in the target body. Do not invent one in the destructor C++.

## Recommended Target Doc Changes

For `by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md`:

- Set metadata:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:000016`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:000016`
  - blank `EMITTER_POSITION_OPTIONAL`
- Replace stale "blank until MSGHandler subobject spelling and base class layout resolved" wording with the current gate analysis:
  - Active combined score is above the `85/85` source gate.
  - Owner/emitter route is valid through [UID:000016].
  - `MSGHandler` subobject spelling is resolved as secondary base inheritance at `this+0x108`.
  - First-draft C++ is ready.
- Add the raw destructor proof:
  - Exact range `0x0046f1e0-0x0046f216`.
  - Five leading and ten trailing `0xcc` padding bytes.
  - No absolute or rel32 inbound references found for `0x0046f1e0`.
  - Constructor parity at `0x0046ff93-0x0046ffc4`.
  - Scalar wrapper parity at `0x004704f0-0x00470579`.
  - Vtable views `0x00613780`, `0x006137e8`, `0x00613818`, `0x00613824`.
  - `MSGHandler::~MSGHandler()` call at `0x0046f209`.
  - Pane-family base tail chain to `0x00544580`.
- Add source/no-code distinction:
  - [UID:00032S] owns/emits the ordinary destructor source body.
  - [UID:00032X] is compiler deleting-destructor and adjustor thunk glue and should keep formal C++ blank.
- Populate formal C++:

```cpp
BrowserControlPaneOld::~BrowserControlPaneOld()
{
}
```

Do not include compiler-generated vtable stores, base destructor calls, delete-flag handling, object free calls, or adjustor thunks in the formal C++ block.

## Recommended Support Doc Changes

### [UID:000016] `by-class/BrowserControlPaneOld.md`

- Recommended score: `COMPLETION:87`, `CONFIDENCE:89` if the supervisor wants support-score movement; otherwise keep current score and update text only.
- Resolve class layout notes:
  - `BrowserControlPaneOld` is best modeled as `ControlPane` plus secondary-base `MSGHandler`.
  - `MSGHandler` base begins at `this+0x108`.
  - `Browser *m_browser` is at `this+0x110`.
  - Complete object size is `0x114`.
- State destructor factoring:
  - [UID:00032S] is the ordinary source destructor and emits an empty destructor body.
  - [UID:00032X] scalar deleting destructor and adjustor thunks are compiler-generated and should not appear as source C++.
- Preserve remaining class-wide caveats only as class-wide caveats:
  - Exact Browser legacy source-file split.
  - Some Browser field/helper names.
  - Final public method spelling for the message override (`HandleBrowserMessage` versus `DispatchMessage`).

### [UID:0000HV] `by-file/Browser.md`

- No required score change.
- Add source-quality sync note:
  - BrowserControlPaneOld's ordinary destructor [UID:00032S] is source-ready with an empty body.
  - Its scalar deleting destructor/adjustor range [UID:00032X] is no-code compiler glue.
  - The class uses a `MSGHandler` secondary base at `+0x108` and a Browser pointer field at `+0x110`.

### [UID:0002P3] Constructor

- No required score change.
- Update support wording to match layout:
  - `MSGHandler` construction at `this+0x108` is secondary-base construction.
  - `this+0x110` is the `Browser *m_browser` field.
  - The scalar wrapper's guarded delete path proves complete object size `0x114`.
- Keep constructor C++ blank unless a broader BrowserControlPaneOld constructor implementation callback resolves Browser/BrowserThread source form.

### [UID:00032X] Scalar Deleting Destructor And Adjustors

- Recommended metadata:
  - `COMPLETION:87`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:FALSE`
  - blank `EMITTER_UIDS`
  - blank formal C++
- Replace any source-bearing implication with no-code proof:
  - MSVC scalar deleting destructor wrapper generated from `BrowserControlPaneOld::~BrowserControlPaneOld()`.
  - Delete-flags parameter tests at `0x0047052b-0x00470531`.
  - Optional object free through `0x004f4ac0`.
  - Guarded/vector-delete helper through `0x0041b6a0` with size `0x114`.
  - Adjustor thunks at `0x00470558`, `0x00470563`, and `0x0047056e`.
  - Source emission belongs to [UID:00032S], not [UID:00032X].

### [UID:0001OB] Browser Vtables And Strings

- Update the BrowserControlPaneOld vtable slice descriptions:
  - `0x00613780`: primary BrowserControlPaneOld vtable; slot `0` points to scalar deleting destructor `0x004704f0`.
  - `0x006137e8`: inherited ControlPane/pane-family secondary view; delete slot is adjustor thunk `0x00470563`.
  - `0x00613818`: inherited ControlPane/pane-family tertiary view; delete slot is adjustor thunk `0x0047056e`.
  - `0x00613824`: `MSGHandler` secondary-base view; delete slot is adjustor thunk `0x00470558`; dispatch slot `0x00613828` points to `0x0046f310`.
- Keep aggregate reconstructability false and C++ blank for the vtable/read-only-data page.

### [UID:0001CO] BrowserControlPaneOldDispatch

- No required score change from this report alone.
- Add support note if touched:
  - The fallback bridge uses the inherited `MSGHandler::m_previousHandler` stored at subobject offset `+4` (outer `this+0x10c`), consistent with B009's MSGHandler source-quality report.
  - Keep final method name caveat (`HandleBrowserMessage` versus `DispatchMessage`) as class-wide, not a destructor blocker.

### MSGHandler Support Docs

- This report agrees with B009's direction:
  - [UID:0001CN] should model `MSGHandler::m_previousHandler` at offset `+4`.
  - [UID:00032S] should describe `0x00528d80` as automatic `MSGHandler` secondary-base teardown.
- Do not block [UID:00032S] on full MSGHandler implementation; the destructor only needs the base/subobject identity, which is resolved.

## Owner / Emitter / C++ Recommendation

- Direct owner: [UID:000016] `BrowserControlPaneOld`.
- Emitter: [UID:000016] through [UID:0000HV] `Browser`.
- Reconstructable: `TRUE`.
- First-draft C++ readiness: ready.
- Recommended formal C++:

```cpp
BrowserControlPaneOld::~BrowserControlPaneOld()
{
}
```

Do not emit any of these in source C++:

- `[this] = 0x00613780`
- `[this+0xa0] = 0x006137e8`
- `[this+0xa4] = 0x00613818`
- `[this+0x108] = 0x00613824`
- direct `MSGHandler::~MSGHandler()` call
- direct `Pane::~Pane()` or `ControlPane::~ControlPane()` call
- delete-flag tests or `operator delete`
- `this` adjustor thunks

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` during the report phase. If the implementation callback is accepted, replace the [UID:00032S] row with:

```text
      - [UID:00032S][0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor](by-memory/0x0046f1e0-0x0046f216.BrowserControlPaneOldNonDeletingDestructor.md) 0x0046f1e0-0x0046f216 | destructor body | BrowserControlPaneOld::~BrowserControlPaneOld : reconstructable : 88% : very strong : B011 2026-06-19 source-quality pass resolves the raw non-modeled body as the ordinary `BrowserControlPaneOld::~BrowserControlPaneOld()` destructor: raw PE/Capstone confirms exact `0x36` body, five-byte leading and ten-byte trailing `0xcc` padding, no absolute or rel32 inbound refs to `0x0046f1e0`, vtable restores to BrowserControlPaneOld primary/ControlPane secondary views `0x00613780/0x006137e8/0x00613818` and MSGHandler secondary-base view `0x00613824`, `MSGHandler::~MSGHandler()` call at `0x0046f209` for the inherited subobject at `this+0x108`, tail chain to `Pane::~Pane()`/pane base cleanup at `0x00544580`, constructor parity at `0x0046ff93-0x0046ffc4`, scalar-wrapper parity at `0x004704f0-0x00470579`, complete object size `0x114`, Browser pointer field `this+0x110`, and first-draft formal C++ as an empty destructor body with vtable stores, MSGHandler/base destructors, delete flags, and adjustor thunks left to compiler lowering.
```

If the implementation also applies the recommended [UID:00032X] no-code reclassification, replace that row with:

```text
      - [UID:00032X][0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors](by-memory/0x004704f0-0x00470579.BrowserControlPaneOldScalarDeletingDestructorAndAdjustors.md) 0x004704f0-0x00470579 | compiler deleting destructor glue | BrowserControlPaneOldScalarDeletingDestructorAndAdjustors : ignored : 87% : very strong : B011 2026-06-19 source-quality pass reclassifies this range as no-code MSVC scalar deleting destructor and adjustor thunk glue generated from `BrowserControlPaneOld::~BrowserControlPaneOld()`: the primary wrapper restores the same four vtable views, calls `MSGHandler::~MSGHandler()` for the `this+0x108` secondary base, calls `Pane::~Pane()` at `0x00544580`, tests delete flags, optionally frees through `0x004f4ac0`, uses guarded/vector-delete size `0x114` through `0x0041b6a0`, and the thunks at `0x00470558/0x00470563/0x0047056e` adjust `this` by `0x108/0xa0/0xa4` before jumping to `0x004704f0`; source emission belongs to [UID:00032S] as the ordinary empty destructor, not to this wrapper range.
```

## Validation Commands Needed After Implementation

Run from `source-3/project-documentation` after applying accepted target/support edits:

> Executable block R001 was removed from this report and preserved verbatim in [00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality-removed.md](00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor-owned coverage row is updated in the same implementation pass, also run:

> Executable block R002 was removed from this report and preserved verbatim in [00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality-removed.md](00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No validators were run for this report-only phase.

## IDA Rename / Type / Comment Recommendations

- Promote raw function at `0x0046f1e0`:
  - Suggested name: `BrowserControlPaneOld::~BrowserControlPaneOld`
  - Confidence: high.
  - Comment: `Ordinary non-deleting destructor; source body is empty. Vtable restores and MSGHandler/Pane teardown are compiler lowering.`
- Rename or confirm `0x004704f0`:
  - Suggested name: `BrowserControlPaneOld_scalar_deleting_destructor`
  - Confidence: high.
  - Comment: `MSVC scalar deleting destructor wrapper for BrowserControlPaneOld; no source body.`
- Rename/confirm adjustor thunks:
  - `0x00470558`: `BrowserControlPaneOld_MSGHandler_scalar_dtor_adjustor`
  - `0x00470563`: `BrowserControlPaneOld_ControlPaneA0_scalar_dtor_adjustor`
  - `0x0047056e`: `BrowserControlPaneOld_ControlPaneA4_scalar_dtor_adjustor`
  - Confidence: high for offsets and role; medium for exact local naming style.
- Type/layout recommendations:
  - `BrowserControlPaneOld : public ControlPane, public MSGHandler`
  - `MSGHandler` base offset: `0x108`
  - `MSGHandler::m_previousHandler`: subobject `+0x4`, outer `+0x10c`
  - `BrowserControlPaneOld::m_browser`: `Browser *` at `+0x110`
  - Complete size: `0x114`
- Vtable comments:
  - `0x00613780`: primary BrowserControlPaneOld vtable.
  - `0x006137e8`: secondary ControlPane/pane-family view, adjustor delete slot.
  - `0x00613818`: tertiary ControlPane/pane-family view, adjustor delete slot.
  - `0x00613824`: MSGHandler secondary-base view, adjustor delete slot plus message dispatch override at `0x00613828`.

## Remaining Issues / Impact

- Exact historical Browser source-file split remains open. It affects class/file documentation polish, not [UID:00032S] source readiness.
- Some Browser object field names and BrowserThread lifecycle names remain incomplete in constructor/class docs. The target destructor does not touch them, so no destructor C++ should invent Browser cleanup.
- The final method spelling for `0x0046f310` may be `HandleBrowserMessage`, `DispatchMessage`, or a project-specific variant. This is a class-wide naming issue and not a destructor blocker.
- Fresh live IDA MCP was unavailable in this session. Raw PE and Capstone evidence was sufficient to resolve the destructor classification; an IDA implementation pass should promote/rename the raw function for tool consistency.

## Changed Files In This Report Phase

- Created `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality.md`.
- No target/support by-* docs edited.
- No coverage report edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00032S"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00032S-BrowserControlPaneOldNonDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00032S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
