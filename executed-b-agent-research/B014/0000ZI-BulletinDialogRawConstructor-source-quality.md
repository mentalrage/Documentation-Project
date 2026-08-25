** TARGET-REPORT-UID:0000ZI **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000ZI BulletinDialogRawConstructor Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:0000ZI] `BulletinDialogRawConstructor` as a source-authored retained out-of-line constructor, not compiler glue and not a passive no-code item.
- Final disposition: keep `CANONICAL_OWNER:00001C`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00001C`; raise target score from `85/86` to `87/88`; add first-draft C++ to the target.
- Required action: supervisor implementation callback should update the target and small support-doc stale wording. Do not edit `by-memory/-coverage-report.md` directly; exact replacement row is included below.
- Confidence: high for identity, owner, argument roles, no direct reachability route, and first-draft constructor shape; medium for the original constant name and whether the declared first parameter was `DialogSession *` or a more-specific `BulletinSession *`.

## Target

- Target UID: `0000ZI`
- Target path: `source-3/project-documentation/by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0000ZI-BulletinDialogRawConstructor-source-quality.md`
- Current scores and route: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:00001C`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001C`, blank C++.
- Current generated route: `auto-generated/-ag-memory-coverage.md` routes this target to `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp`; current generated file contains only an empty emitter marker for `0000ZI`.

## Executive Recommendation

`0x00472000-0x0047203a` should be documented as:

```cpp
BulletinDialog::BulletinDialog(DialogSession *session, unsigned char dialogType)
    : DialogInSession(session, kBoardDialogConfigId, dialogType)
{
}
```

Use literal `2` instead of `kBoardDialogConfigId` in the formal target C++ if support docs are not ready to define a named constant:

```cpp
BulletinDialog::BulletinDialog(DialogSession *session, unsigned char dialogType)
    : DialogInSession(session, 2, dialogType)
{
}
```

The constant `2` is not the `BulletinDialog` dialog-type byte. It is the shared `DialogPane` config/id/style argument passed through `DialogInSession` into `DialogPane::DialogPane(L"", 2, 1)`. The caller-supplied second argument is the `DialogInSession +0x26c` dialog-type/subtype byte. The first argument is the owning session pointer/data stored at `DialogInSession +0x270`; in board dialog consumers it is used as the owning `DialogSession` / `BulletinSession` pointer.

## Supervisor Active Recheck

- The target is not mixed and does not require a split. The half-open range is clean: constructor bytes at `0x00472000-0x0047203a`, `0xcc` padding before and after, and the next modeled function begins at `0x00472040`.
- The assignment route is already valid under the current gate: child average `85.5`, owner class [UID:00001C] `85/87`, and file parent [UID:0000HT] currently `86/87`.
- The stale blocker is not ownership. It is source-quality wording: old 95/95 code-entry language, unresolved/passive reachability wording, and incorrect or ambiguous argument role text.

## Inference Research Guidance Check

- `by-structure.md` current rule permits C++ when `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS` is nonblank and reaches a generated source root, and `(COMPLETION + CONFIDENCE) / 2 > 85`. This target already meets that minimum.
- `inference_research.md` guidance supports negative reachability conclusions only after checking xrefs, raw pointers, vtables, constructors, and adjacent functions. I performed those checks with existing docs and direct PE scans because IDA MCP was unavailable.
- Existing docs were treated as leads. The report rechecked the constructor, sibling `DialogInSession` call pattern, vtable references, generated route, and no-xref claim.

## Heuristic / Inference Reanalysis And Validation

### Source Placement

- Best direction: `BulletinDialog` class under [UID:0000HT] `BoardDialogs`.
- Evidence: target stores `BulletinDialog` primary/secondary/tertiary vtables; class doc owns constructor, command bridge, scalar destructor companion, and exact vtable data; file doc places `BulletinDialog`, `BoardListDialog`, article dialogs, and shared board/article helpers under `ui/dialogs/BoardDialogs.cpp`.
- Rejected: `DialogSession.cpp` owns the `DialogInSession` base, not this derived constructor. `BulletinSession.cpp` constructs and routes board/mail dialogs but does not own their class constructors.

### Raw Reachability / Liveness

- Direct route result: negative. Direct PE scan found zero rel32 call/jump refs to `0x00472000`, zero absolute VA dword hits for `0x00472000`, and zero RVA dword hits for `0x00072000`.
- Vtable-store route result: only this raw constructor stores the `BulletinDialog` vtable bases. Direct PE scan found exactly one dword hit each for `0x00613ba8`, `0x00613c0c`, and `0x00613c3c`, all inside the constructor immediates.
- Best inference: retained out-of-line source constructor, likely unused directly because the concrete board/article/mail constructors inline or independently repeat the `DialogInSession(session, 2, type)` base-construction pattern and then install their own vtables. This is not an ABI thunk or vtable data item.
- Score impact: no live route caps completion/confidence below final-audit levels, but it does not block first-draft C++ because the body is a complete source-authored constructor and has a valid emitter route.

### Constructor Signature And Argument Roles

- Recommended source signature: `BulletinDialog::BulletinDialog(DialogSession *session, unsigned char dialogType)`.
- `session`: pushed as the first `DialogInSession` argument and stored by the base at `+0x270`; board dialog methods later treat this field as the owning session object.
- `2`: common `DialogPane` config/id/style argument passed to `DialogInSession`, then to `DialogPane::DialogPane(L"", 2, 1)`.
- `dialogType`: caller-supplied byte stored by `DialogInSession` at `+0x26c`. Sibling constructors hardcode this byte as `0` for `BoardListDialog`, `1` for `ArticleListDialog`, `2` for `ArticleDialog`, `4` for `NewArticleDialog`, `5` for `NewPredefinedFormArticleDialog`, `6` for `MailListDialog`, `7` for `MailDialog`, and `8` for `NewMailDialog`.
- Rejected: current target wording that treats `[ebp+0x0c]` as a visible/button flag is weaker. The sibling constants and `DialogSessionLayouts.md` make `dialogType` / `dialogSubtype` the better source-facing name.

### Generated / Raw Name Handling

- `sub_4A1400` should be rendered as `DialogInSession::DialogInSession`.
- Vtable labels `??_7BulletinDialog@@6B@`, `_0`, and `_1` are compiler names but useful binary evidence. Source C++ should not write vptr stores directly.
- The scalar deleting destructor and adjustor thunks are compiler-generated/no-code support; this constructor is not in that category.

### No-Function-Object Policy

- IDA not modeling `0x00472000` as a function is a tooling/boundary issue caused by absent direct xrefs, not evidence that the bytes are non-source.
- Recommended IDA action: create a function at `0x00472000-0x0047203a` only after review, then rename/type it as the constructor. Do not force ordinary caller evidence into the docs.

### First-Draft C++ Readiness

- Ready. The target range is exactly one complete constructor body, the source shape is a one-line initializer list, vptr writes are compiler output, and the owner/emitter route is valid.
- Remaining uncertainty is naming, not behavior: `kBoardDialogConfigId` is a descriptive constant name, not proven original. Use literal `2` if final support declarations are not available.

## Evidence Checked

### Documentation

- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`
- Target page `by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md`
- Support pages:
  - `by-class/BulletinDialog.md`
  - `by-file/BoardDialogs.md`
  - `by-class/DialogInSession.md`
  - `by-file/DialogSession.md`
  - `by-type/by-struct/DialogSessionLayouts.md`
  - `by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md`
  - `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`
  - `by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md`
  - `by-type/by-vtable/BulletinDialogVtables.md`
  - `by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md`
  - `by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md`
  - `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`
  - `by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md`
  - `by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md`
- Coverage/generated:
  - `auto-generated/-ag-memory-coverage.md`
  - `by-memory/-coverage-report.md`
  - `auto-generated/NexusTK/ui/dialogs/BoardDialogs.cpp`

### IDA MCP Status

- `GET http://127.0.0.1:13337/mcp` timed out.
- JSON-RPC `tools/list` POST to `http://127.0.0.1:13337/mcp` returned `Unable to connect to the remote server`.
- No IDA database writes were made.

### Direct PE Evidence

Read-only PE used: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c600`
- `.rdata`: `0x0060d000-0x0066c200`

Disassembly confirms:

```asm
00472000  push    ebp
00472001  mov     ebp, esp
00472003  push    ecx
00472004  push    esi
00472005  push    dword ptr [ebp + 0xc]
00472008  mov     esi, ecx
0047200A  push    2
0047200C  push    dword ptr [ebp + 8]
0047200F  mov     dword ptr [ebp - 4], esi
00472012  call    0x4a1400
00472017  mov     dword ptr [esi], 0x613ba8
0047201D  mov     eax, esi
0047201F  mov     dword ptr [esi + 0xa0], 0x613c0c
00472029  mov     dword ptr [esi + 0xa4], 0x613c3c
00472033  pop     esi
00472034  mov     esp, ebp
00472036  pop     ebp
00472037  ret     8
```

Padding:

- `0x00471ff1-0x00472000`: all `0xcc`
- `0x0047203a-0x00472040`: all `0xcc`
- `0x00472069-0x00472070`: all `0xcc` after the command bridge

Reachability scans:

- Rel32 refs to `0x00472000`: `0`
- Absolute dword hits for `0x00472000`: `0`
- RVA dword hits for `0x00072000`: `0`
- Dword hits for `0x00613ba8`: exactly one, at `.text` VA `0x00472019`
- Dword hits for `0x00613c0c`: exactly one, at `.text` VA `0x00472025`
- Dword hits for `0x00613c3c`: exactly one, at `.text` VA `0x0047202f`

Sibling `DialogInSession` constructor calls found by rel32 scan:

| Callsite | Caller context | Third argument into `DialogInSession` |
| --- | --- | --- |
| `0x00472012` | `BulletinDialog` raw constructor | caller-supplied `[ebp+0x0c]` |
| `0x004720c8` | `BoardListDialog` constructor | `0` |
| `0x00472cf8` | `ArticleListDialog` constructor | `1` |
| `0x00475445` | `ArticleDialog` constructor | `2` |
| `0x00476c51` | `NewArticleDialog` constructor | `4` |
| `0x004777e9` | `NewPredefinedFormArticleDialog` constructor | `5` |
| `0x00479168` | `MailListDialog` constructor | `6` |
| `0x0047b282` | `MailDialog` constructor | `7` |
| `0x0047d09c` | `NewMailDialog` constructor | `8` |

Every sibling call pushes common second argument `2` before calling `0x004a1400`, confirming `2` is the shared `DialogPane` config/id/style argument, not a class-specific bulletin type.

## Direct Xref / Caller Inventory

| Address / item | Result | Meaning |
| --- | --- | --- |
| `0x00472000` | no rel32 call/jump refs; no VA/RVA dword hits | no direct live construction/pointer route found |
| `0x00472012 -> 0x004a1400` | direct base constructor call | source constructor delegates to `DialogInSession` |
| `0x00472017/1f/29` | only hits to `BulletinDialog` vtable bases | constructor is the only body that installs these exact base tables |
| `0x00472040` | nine vtable dword refs, no rel32 refs | separate shared command bridge; not part of constructor |

## Ranked Ownership Analysis

### 1. [UID:00001C] BulletinDialog

- Evidence for: three `BulletinDialog` vtable stores; exact `BulletinDialogVtableData` child; class doc owns constructor and destructor evidence; source route reaches `BoardDialogs.cpp`.
- Evidence against: no direct constructor callers and IDA has no function object at the start.
- Decision: accept as direct semantic owner. The negative caller result is liveness evidence, not ownership evidence against the class.

### 2. [UID:0000HT] BoardDialogs

- Evidence for: class parent routes to this file; proposed tree places board/article dialog family under `ui/dialogs/BoardDialogs.cpp`; generated route confirms `BoardDialogs.cpp`.
- Evidence against: file-level page still has unresolved final partition between `BoardDialogs.cpp`, `ArticleDialogs.cpp`, and related companions.
- Decision: keep as file parent/emitter root through `BulletinDialog`.

### 3. [UID:0000IU] DialogSession / [UID:00003S] DialogInSession

- Evidence for: target calls `DialogInSession::DialogInSession`.
- Evidence against: base callee ownership does not own derived constructor; vtable stores are `BulletinDialog`.
- Decision: reject as direct owner. Keep as dependency/support page.

### 4. No-code/generated artifact

- Evidence for: no direct xrefs and raw/no-function-object state.
- Evidence against: normal constructor prologue/epilogue, base constructor call, class vtable installs, `ret 8`, and sibling source-constructor pattern. Compiler-generated thunks/data are documented separately.
- Decision: reject. Use first-draft C++.

## Recommended Exact Target Changes

### Metadata

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00001C | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00001C | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Reconstruction C++

Preferred if support docs define a constant:

```cpp
BulletinDialog::BulletinDialog(DialogSession *session, unsigned char dialogType)
    : DialogInSession(session, kBoardDialogConfigId, dialogType)
{
}
```

Safe literal-only target draft:

```cpp
BulletinDialog::BulletinDialog(DialogSession *session, unsigned char dialogType)
    : DialogInSession(session, 2, dialogType)
{
}
```

### Behavior / Constructor Shape Replacement Text

Replace the current behavior paragraph that describes "parent/session id, dialog type `2`, and caller-supplied visible/button flag" with:

```markdown
The body is a retained out-of-line `BulletinDialog` constructor. It passes the owning `DialogSession`/session pointer argument to `DialogInSession`, passes common `DialogPane` config/id/style constant `2`, and passes the caller-supplied `dialogType` byte that `DialogInSession` stores at `this + 0x26c`. `DialogInSession` stores the session pointer/data at `this + 0x270`. The visible stores after the base-constructor call are compiler-emitted vptr writes for the primary and secondary/tertiary views.
```

### Reachability / Liveness Text

Add or replace the passive live-reachability caveat with:

```markdown
Current direct-route evidence resolves reachability negatively rather than passively open: IDA history and the B014 PE scan found no direct `rel32` call/jump to `0x00472000`, no absolute VA dword hit for `0x00472000`, and no RVA dword hit for `0x00072000`. The three `BulletinDialog` vtable-base immediates occur only inside this raw body. The best inference is a retained out-of-line source constructor with no direct construction path in the shipped binary, while concrete board/article/mail constructors independently call `DialogInSession(session, 2, <type>)` and install their own vtables.
```

### Assignment Gate / C++ Policy Text

Replace stale 95/95 language with:

```markdown
This page now clears the active reconstruction code-entry gate: `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001C`, generated route through [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), and combined score above `85`. The raw no-function-object state remains documented and caps the score, but it does not block first-draft C++ because the covered range is one complete source-authored constructor body.
```

## Recommended Support-Doc Changes

- `by-class/BulletinDialog.md`: update constructor row/signature to `BulletinDialog(DialogSession *session, unsigned char dialogType)`; replace "C++ intentionally blank because raw reachability unresolved" with "direct reachability resolved negative; constructor target emits first-draft C++; class virtual names still provisional."
- `by-file/BoardDialogs.md`: in the `BulletinDialog` row, replace "constructor bytes confirmed but start is not an IDA function object" as a final blocker with "raw retained out-of-line constructor, no direct route, source shape ready in child."
- `by-type/by-vtable/BulletinDialogVtables.md`: replace stale "final C++ remains blank under the 95/95 reconstruction gate" with current policy: vtable data remains no-code/generated-binary support, while the constructor child may emit source C++.
- `by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md`: no score change required; optionally add that B014 direct PE scan reconfirmed the three vtable-base immediates occur only in `0x00472000`.
- `by-class/DialogInSession.md` and `by-type/by-struct/DialogSessionLayouts.md`: clarify constructor signature as `DialogInSession(DialogSession *session, int dialogPaneConfigId, unsigned char dialogType)` or equivalent. Existing layout facts already support this; the important support fix is to avoid describing the common `2` as the stored dialog-type byte.

## Score / Metadata Recommendation

| Item | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| `0000ZI` completion | 85 | 87 | resolved argument roles, constant role, source shape, reachability negative route, and first-draft C++ |
| `0000ZI` confidence | 86 | 88 | direct PE scans corroborate existing IDA/no-xref/vtable evidence |
| `CANONICAL_OWNER` | `00001C` | unchanged | direct class owner is proven by vtable stores |
| `EMITTER_UIDS` | `00001C` | unchanged | generated route reaches `BoardDialogs.cpp` |
| C++ | blank | populate | current gate met and source shape is safe |

Support scores may be raised modestly if edited:

- `BulletinDialog.md`: `85/87` to `86/88` if the constructor signature/liveness conclusion and child C++ readiness are incorporated.
- `BoardDialogs.md`: no required score change; it is already `86/87`.
- `BulletinDialogVtables.md`: no required score change; stale C++ policy wording can be updated without score movement.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. Replace the existing row for `0000ZI` with:

```markdown
    - [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md) 0x00472000-0x0047203a | raw retained constructor body | BulletinDialogRawConstructor : reconstructable : 87% : strong : B014 source-quality recheck resolves the stale no-code gate: direct rel32/VA/RVA scans and prior IDA no-xref evidence find no live pointer/caller route, while raw bytes and vtable-store scans prove a source-authored retained `BulletinDialog(DialogSession*, unsigned char)` constructor that delegates to `DialogInSession(session, 2, dialogType)` and installs three vtables. The constant `2` is the shared DialogPane config/id/style passed through `DialogInSession`, not the caller-supplied dialog-type byte; `+0x26c` receives the type byte and `+0x270` receives the owning session pointer. First-draft C++ is ready under the current score/emitter gate; scalar-delete, adjustor thunk, and vtable-data pages remain compiler-generated/no-code support.
```

## Validator Needs

No validator command was run because this was report-only and no by-* docs were edited.

Recommended implementation validation after accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000ZI-BulletinDialogRawConstructor-source-quality-removed.md](0000ZI-BulletinDialogRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support edits are limited to the target only, the first and autogen commands are enough.

## IDA Rename / Type / Comment Recommendations

Do not write these during this report pass.

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x00472000` | create function `BulletinDialog__ctor` / `BulletinDialog::BulletinDialog` after reviewer approval | high |
| `0x00472000` type | `BulletinDialog *__thiscall BulletinDialog_ctor(BulletinDialog *this, DialogSession *session, unsigned char dialogType)` | medium-high |
| `0x0047200a` | comment: `2` is common DialogPane config/id/style argument for session-bound board/mail dialogs | high |
| `0x00472005` / `0x0047200c` | comment arg roles: `dialogType` to `+0x26c`, `session` to `+0x270` through base constructor | high |
| `0x004a1400` | prefer name/type `DialogInSession::DialogInSession(DialogSession *session, int dialogPaneConfigId, unsigned char dialogType)` | medium-high |
| Vtable labels `0x00613ba8`, `0x00613c0c`, `0x00613c3c` | keep current `BulletinDialog` vtable labels; no source-array emission | high |

## Open Questions / Remaining Uncertainty

- Original constant name for `2` is not recoverable from stripped binary. `kBoardDialogConfigId` is descriptive. Use literal `2` if final naming discipline prefers only proven names in C++ snippets.
- First parameter may have been declared as `DialogSession *`, `BulletinSession *`, or a local typedef/interface. Current support docs favor `DialogSession *` as the stable base type; board/bulletin callers make `BulletinSession *` plausible but narrower.
- No direct shipped-binary construction route was found. This should remain in evidence and keep scores conservative, but it should no longer be phrased as an unattempted blocker.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0000ZI-BulletinDialogRawConstructor-source-quality.md`
- Modified: none
- Target/support by-* docs: not edited
- `by-memory/-coverage-report.md`: not edited

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0000ZI-BulletinDialogRawConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0000ZI"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000ZI-BulletinDialogRawConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0000ZI-BulletinDialogRawConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000ZI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
