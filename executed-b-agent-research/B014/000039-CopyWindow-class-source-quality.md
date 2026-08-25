** TARGET-REPORT-UID:000039 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B014 B-source-quality report: [UID:000039] CopyWindow

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/000039-CopyWindow-class-source-quality.md`  
Target path: `source-3/project-documentation/by-class/CopyWindow.md`  
Assignment: report-only source-quality / heuristic pass.  
Status: FINISHED for supervisor review. No by-* documentation and no coverage report files were edited.

## Finalized Report / Current Recommendation

- Current recommendation: raise `by-class/CopyWindow.md` from `85/86` to `88/90`, keep owner/emitter [UID:0000IH][CopyWindow](by-file/CopyWindow.md), and add declaration-level first-draft C++ for a small `AlertPane` subclass.
- Final disposition: `CopyWindow` is a real dedicated dialog class in `NexusTK/ui/dialogs/CopyWindow.cpp`, not a `TextEditPane`, `ReconnectDialog`, or generic `AlertPanes` class.
- Required action: update the class, file, exact memory island, vtable/string support, and relevant coverage rows with the Rule 26 details below. Do not move the report to `executed` until the accepted implementation callback is applied and validated.
- Confidence: high. The standalone constructor is raw/no-direct-route, but its byte body is complete, duplicated by live inline construction in the reconnect helper, and tied to class vtables, button literals, and accept/cancel callbacks.

## Target

- Target UID: `000039`
- Target path: `source-3/project-documentation/by-class/CopyWindow.md`
- Current target score: `COMPLETION:85`, `CONFIDENCE:86`
- Current owner/emitter: `CANONICAL_OWNER:0000IH`, `EMITTER_UIDS:0000IH`
- Current generated output: `auto-generated/NexusTK/ui/dialogs/CopyWindow.cpp`, but all CopyWindow-related items currently emit only empty markers.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/000039-CopyWindow-class-source-quality.md`

## Evidence Checked

Required instructions:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B014/goal.md`
- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`

Primary and support docs:

- `source-3/project-documentation/by-class/CopyWindow.md`
- `source-3/project-documentation/by-file/CopyWindow.md`
- `source-3/project-documentation/by-memory/0x005544c0-0x0055454b.CopyWindow.md`
- `source-3/project-documentation/by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md`
- `source-3/project-documentation/by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md`
- `source-3/project-documentation/by-file/ReconnectDialog.md`
- `source-3/project-documentation/by-class/ConnectionClosedDialog.md`
- `source-3/project-documentation/by-class/ReconnectDialog.md`
- `source-3/project-documentation/by-class/AlertPane.md`
- `source-3/project-documentation/by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md`
- `source-3/project-documentation/by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md`
- `source-3/project-documentation/by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md`
- `source-3/project-documentation/by-file/TextEditPane.md`
- `source-3/project-documentation/by-class/TextEditPane.md`
- `source-3/project-documentation/by-global/g_pActiveTextEditPane.md`
- `source-3/project-documentation/by-memory/0x0069be00-0x0069be04.g_pActiveTextEditPane.md`
- `source-3/project-documentation/by-global/g_pLanguageMan.md`
- `source-3/project-documentation/by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md`
- `source-3/project-documentation/by-memory/0x0067a740-0x0067a744.g_pBackPane.md`
- `source-3/project-documentation/by-resource/str-res-localized-strings.md`
- `source-3/project-documentation/by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md`
- `source-3/project-documentation/by-memory/0x00622e78-0x00622f1c.CopyWindowVtableData.md`
- `source-3/project-documentation/by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md`
- `source-3/project-documentation/by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`
- `source-3/project-documentation/auto-generated/NexusTK/ui/dialogs/CopyWindow.cpp`
- `source-3/project-documentation/auto-generated/-ag-class-coverage.md`
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
- coverage rows in `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-memory/-coverage-report.md`

Prior research leads checked:

- `Agent-B002/research/executed/00000B-alertpane-source-quality.md`
- B001/B002 executed string-tail and word-refcount reports mentioning the CopyWindow island and surrounding ranges
- B014 `00010T-ClanDestructorBand-source-routing.md` for the shared alert-family destructor/thunk route

Fresh tool evidence:

- IDA MCP endpoint `http://127.0.0.1:13337/mcp` was attempted and was unavailable in this session: `Unable to connect to the remote server`.
- Fresh local PE scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:
  - MD5 `4247e04e20b65d6414c7238aa8ff5515`
  - SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
  - image base `0x00400000`
  - `.text 0x00401000-0x0060c4ac`
  - `.rdata 0x0060d000-0x0066c0be`
  - `.data 0x0066d000-0x0069ce24`
  - `.rsrc 0x0069d000-0x006b2c38`
- Numeric conversions verified with `tools/int_convert.py`:
  - `0xf1 == 241`
  - `0x270 == 624`
  - `0xa0 == 160`
  - `0xa4 == 164`
  - `0x53 == 83`
  - `0x16 == 22`
  - `0x0b == 11`
  - `0x0d == 13`
  - `0x0a == 10`

## Executive Recommendation

`CopyWindow` should emit class-level first-draft C++ as an `AlertPane` subclass with no data fields of its own and two override methods corresponding to the `AlertPane` primary/secondary callback slots. The behavior names `OnAccept` and `OnCancel` are good documentation aliases, but source C++ should use the base-compatible names `OnPrimaryButton()` and `OnSecondaryButton()` unless the `AlertPane` base is later renamed project-wide.

The exact executable child [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md) should emit the constructor and callback method bodies. It should be raised from `86/86` to `88/90`. The raw constructor start is not an IDA-modeled function and has no direct call target, but the body is a complete source-authored constructor, and the reconnect helper duplicates the same construction sequence inline for live reachability.

The vtable and string children should remain no-code/generated-data support. Their source semantics are already represented by the class declaration and constructor body: vtables are compiler-generated from the class, and the `L"Yes"` / `L"No"` literals are source-use constants in the constructor, not separate standalone source declarations.

## Heuristic / Inference Reanalysis And Validation

### Raw constructor modeling and reachability

Best inference: `0x005544c0-0x00554513` is a retained out-of-line `CopyWindow::CopyWindow()` constructor body.

Evidence:

- Fresh disassembly:

```text
005544c0: push   ebp
005544c1: mov    ebp, esp
005544c3: push   ecx
005544c4: push   esi
005544c5: push   0x622f3c
005544ca: push   0x622f44
005544cf: push   dword ptr [0x67a740]
005544d5: mov    esi, ecx
005544d7: mov    ecx, dword ptr [0x67a750]
005544dd: push   0xf1
005544e2: mov    dword ptr [ebp - 4], esi
005544e5: call   0x4f0350
005544ea: push   eax
005544eb: mov    ecx, esi
005544ed: call   0x49feb0
005544f2: mov    dword ptr [esi], 0x622e7c
005544f8: mov    eax, esi
005544fa: mov    dword ptr [esi + 0xa0], 0x622ee4
00554504: mov    dword ptr [esi + 0xa4], 0x622f14
0055450e: pop    esi
0055450f: mov    esp, ebp
00554511: pop    ebp
00554512: ret
```

- It calls `LanguageMan` lookup helper `0x004f0350` with id `0xf1` / 241 (Verified with `int_convert.py`), then calls `AlertPane::AlertPane` at `0x0049feb0`.
- It installs exactly the three `CopyWindow` vtable views at `+0x00`, `+0xa0` / 160, and `+0xa4` / 164 (offset conversions verified with `int_convert.py`).
- It returns `this` in `eax`, matching ordinary thiscall constructor shape.
- It is bounded by eight `0xcc` bytes before the constructor and thirteen `0xcc` bytes after the constructor.

Negative evidence:

- Fresh PE scan found zero rel32 call/jump refs to `0x005544c0`.
- Fresh PE scan found zero absolute VA dword hits and zero RVA dword hits for `0x005544c0`.
- IDA-backed docs report that the start remains "Not a function."

Decision:

- The no-direct-route state should remain documented as reachability evidence, but it should no longer block first-draft C++. The range is one complete source-authored constructor body with valid owner/emitter route and current combined score above the code-entry gate.
- The most likely compiler/source shape is that the current known live caller path inlined the constructor body while the compiler/linker retained the out-of-line constructor. That is common enough for C++ constructors and explains the raw no-call state without reclassifying the body as dead or compiler glue.

Rejected alternatives:

- "Dead non-source bytes": rejected because the body has a complete constructor prologue/epilogue, calls the base constructor, stores class vtables, and is duplicated by the live inline construction path.
- "ReconnectDialog-owned helper": rejected because only the inline copy appears in the reconnect helper; the class vtables, callbacks, and labels are `CopyWindow`-specific.
- "Compiler-generated glue only": rejected because the body performs source constructor work and calls source helper/base constructors. The vtable stores are compiler-emitted within a source-authored constructor, not standalone compiler glue.

### Accept/cancel callback names

Best source-quality direction:

- Documentation behavior aliases: `OnAccept` and `OnCancel` are clear and should be preserved in prose/tables as "primary/accept/yes" and "secondary/cancel/no" behaviors.
- Formal C++ names: use `OnPrimaryButton()` and `OnSecondaryButton()` to match the resolved [UID:00000B][AlertPane](by-class/AlertPane.md) base declaration.

Evidence:

- `AlertPane` docs now emit `virtual void OnPrimaryButton();` and `virtual void OnSecondaryButton();`.
- `AlertPane::DismissDialog(int buttonId, int unused)` dispatches those no-argument slots for button ids `1` and `2`.
- `CopyWindow` vtable data has `0x00554520` and `0x00554540` in the corresponding primary-table callback slots at `0x00622ed8` and `0x00622edc`.

Fresh callback disassembly:

```text
00554520: mov    ecx, dword ptr [0x69be00]
00554526: call   0x590520
0055452b: mov    dword ptr [0x69be00], 0
00554535: ret

00554540: mov    dword ptr [0x69be00], 0
0055454a: ret
```

Decision:

- Rename source-facing C++ callbacks to `CopyWindow::OnPrimaryButton()` and `CopyWindow::OnSecondaryButton()`.
- Keep `OnAccept` / `OnCancel` as behavior aliases only, unless the `AlertPane` base names are globally changed later.
- Do not add a null guard in first-draft C++; the binary unconditionally calls `TextEditPane::SelectAll` through `g_pActiveTextEditPane` on accept.

### Active TextEditPane global naming

Best source name: `g_pActiveTextEditPane`.

Evidence:

- [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md) documents `0x0069be00`, constructor writes in `TextEditPane`, destructor clears in `TextEditPane`, and CopyWindow consumers.
- Fresh PE scan found eight absolute VA occurrences of `0x0069be00`: one read in `0x00553e60`, three CopyWindow callback accesses at `0x00554520/0x0055452b/0x00554540`, two constructor writes in `TextEditPane`, and two destructor clears in `TextEditPane`.
- Generated alias `g_pCopyWindowTextEditPane` describes only one consumer and is too narrow.

Decision:

- Use `g_pActiveTextEditPane` in target/support docs and C++.
- Reject `g_pCopyWindowTextEditPane`, `dword_69BE00`, and CopyWindow-owned global naming.

### Reconnect-flow inline construction versus class ownership

Best source-placement decision:

- `0x00553e60-0x00553f36` remains a `ReconnectDialog.cpp` / `ConnectionClosedDialog` init helper.
- The CopyWindow allocation inside it is a live call-site construction / inline constructor expansion of the `CopyWindow` class, not a reason to move the helper to `CopyWindow.cpp`.

Evidence:

- Existing IDA-backed docs list three callers to `0x00553e60`: `0x00553ca8`, `0x00553d55`, and `0x005543bb`, all in connection/reconnect construction or reconnect button flow.
- Fresh PE rel32 scan reconfirmed those three rel32 callers to `0x00553e60`.
- Fresh disassembly of the inline slice:

```text
00553e84: mov    ecx, dword ptr [0x69be00]
00553e8a: test   ecx, ecx
00553e8c: je     0x553efe
00553e8e: call   0x58efa0
00553e93: test   ax, ax
00553e96: jle    0x553efe
00553e98: push   0x270
00553e9d: call   0x4f4aa0
...
00553ebb: push   0x622f3c
00553ec0: push   0x622f44
00553ec5: push   dword ptr [0x67a740]
00553ecb: push   0xf1
00553ed0: call   0x4f0350
00553ed5: push   eax
00553ed6: mov    ecx, esi
00553ed8: call   0x49feb0
00553edd: mov    dword ptr [esi], 0x622e7c
00553ee3: mov    dword ptr [esi + 0xa0], 0x622ee4
00553eed: mov    dword ptr [esi + 0xa4], 0x622f14
```

- `0x0058efa0` is not a CopyWindow method. Fresh disassembly shows it returns `word ptr [[this+0x134]+0x0c]`, i.e. the current text length/character count of the active `TextEditPane`. Best source-facing name is `TextEditPane::GetTextLength()` or `TextEditPane::GetCharCount()`.
- The allocation size is `0x270` / 624 bytes (Verified with `int_convert.py`), matching the alert/dialog object family size.

Decision:

- Update `ConnectionClosedDialogInitHelper` support docs to name `0x0058efa0` descriptively as a TextEditPane length query and state that the helper opens a CopyWindow prompt only when the active editor pointer is non-null and has positive text length.
- Keep `0x00553e60` owner/emitter under [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md).

### Localized and button string routing

Best source-quality corrections:

- `dword_67A750` is [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md).
- `0x004f0350` is `LanguageMan` localized string lookup.
- `0xf1` / 241 (Verified with `int_convert.py`) is the CopyWindow prompt string id. The report did not decode the actual text from `STR.RES`; keep it as an id unless a resource pass maps it.
- `dword_67A740` is [UID:00028J][g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md), passed as the `AlertPane` layout/reference pointer.
- `0x00622f44` is UTF-16LE `Yes`, not a pointer table or `off_622F44`.
- `0x00622f3c` is UTF-16LE `No`.

Evidence:

- `g_pLanguageMan` docs document `dword_67A750` and the `0x004f0350` lookup route.
- `g_pBackPane` docs document `dword_67A740` as the root/back pane pointer used as pane parent/context by many dialogs.
- Fresh PE bytes:

```text
0x00622f3c: 4e 00 6f 00 00 00 00 00  -> UTF-16LE "No"
0x00622f44: 59 00 65 00 73 00 00 00  -> UTF-16LE "Yes"
```

- Fresh PE scan found exactly two absolute VA hits for `0x00622f3c`: `0x00553ebc` and `0x005544c6`.
- Fresh PE scan found exactly two absolute VA hits for `0x00622f44`: `0x00553ec1` and `0x005544cb`.

Decision:

- Replace target/support wording that says "button table `off_622F44`" with "primary label `L\"Yes\"` at `0x00622f44` and secondary label `L\"No\"` at `0x00622f3c`."
- The first-draft constructor should pass `L"Yes"` then `L"No"` to `AlertPane`, matching the base constructor signature.

### Vtable slices and adjustors

Best route:

- `CopyWindow` owns [UID:0003CV][0x00622e78-0x00622f1c.CopyWindowVtableData](by-memory/0x00622e78-0x00622f1c.CopyWindowVtableData.md) as source-declared/generated-binary support.
- Formal C++ should declare the class/overrides; vtable bytes remain no-code.

Fresh vtable dword scan:

```text
0x00622e78  0x0064eb30  RTTI/COL
0x00622e7c  0x0048c550  primary alert-family scalar deleting destructor
...
0x00622ec4  0x004a0580  AlertPane::DismissDialog
...
0x00622ed8  0x00554520  CopyWindow primary/accept callback
0x00622edc  0x00554540  CopyWindow secondary/cancel callback
0x00622ee0  0x0064eb94  secondary RTTI/COL
0x00622ee4  0x0048c315  +0xa0 adjustor thunk
...
0x00622f10  0x0064eba8  tertiary RTTI/COL
0x00622f14  0x0048c320  +0xa4 adjustor thunk
0x00622f18  0x00544e90
```

Evidence:

- Existing vtable doc records primary base `0x00622e7c`, adjusted bases `0x00622ee4` and `0x00622f14`, constructor stores from both the raw constructor and inline construction helper, and the end boundary before `0x00622f1c`.
- Shared alert destructor docs confirm `0x0048c550`, `0x0048c315`, and `0x0048c320` are alert-family compiler-generated destructor/deleting thunks used by AlertPane, BlueAlertPane, CopyWindow, QuitDialog, and ClanLeaveConfirmDialog.

Decision:

- Do not emit vtable data as C++ arrays.
- Add class/support text saying the vtable child should regenerate from `class CopyWindow : public AlertPane` with overrides for the two callback slots.

### Source file placement

Best file: `NexusTK/ui/dialogs/CopyWindow.cpp`, current [UID:0000IH][CopyWindow](by-file/CopyWindow.md).

Evidence:

- `by-project-structure/proposed-source-tree.md` already names `ui/dialogs/CopyWindow.cpp`.
- The class is a tiny `AlertPane` subclass with its own vtable data and constructor/callback island.
- The class consumes TextEditPane state but does not own the active-editor global or text-edit implementation.
- The reconnect helper constructs the object conditionally but has reconnect-flow callers and post-construction reconnect/session side effects.

Rejected placements:

- `TextEditPane.cpp`: rejected because TextEditPane owns `g_pActiveTextEditPane` and `SelectAll`, but `CopyWindow` has its own alert class/vtable and source-file page.
- `ReconnectDialog.cpp`: rejected as class owner because the helper only contains an inline construction side path. Keep support reference there.
- `AlertPanes.cpp`: rejected because `AlertPane` owns the base; `CopyWindow` is a feature-specific text-edit prompt derived from the base.
- New source file: not needed. Existing `CopyWindow.cpp` file page is narrow and already matches the proposed source tree.

## IDA / PE Facts

Fresh PE facts from this pass:

- `0x005544b8-0x005544c0`: eight `0xcc` bytes before the raw constructor.
- `0x005544c0-0x00554513`: raw constructor-shaped body, size `0x53` / 83 bytes (Verified with `int_convert.py`).
- `0x00554513-0x00554520`: thirteen `0xcc` bytes (Verified with `int_convert.py`).
- `0x00554520-0x00554536`: accept/primary callback, size `0x16` / 22 bytes (Verified with `int_convert.py`).
- `0x00554536-0x00554540`: ten `0xcc` bytes (Verified with `int_convert.py`).
- `0x00554540-0x0055454b`: cancel/secondary callback, size `0x0b` / 11 bytes (Verified with `int_convert.py`).
- `0x00554550-0x0055455b`: next helper clears `0x0067ab54`; excluded from CopyWindow.
- Zero rel32 call/jump refs to `0x005544c0`, `0x00554520`, and `0x00554540`.
- Vtable data refs only for `0x00554520` and `0x00554540`: `0x00622ed8` and `0x00622edc`.
- Zero absolute VA/RVA dword hits for `0x005544c0`.
- Vtable base absolute hits:
  - `0x00622e7c`: `0x00553edf`, `0x005544f4`
  - `0x00622ee4`: `0x00553ee9`, `0x00554500`
  - `0x00622f14`: `0x00553ef3`, `0x0055450a`
- Button literal absolute hits:
  - `0x00622f3c`: `0x00553ebc`, `0x005544c6`
  - `0x00622f44`: `0x00553ec1`, `0x005544cb`
- `0x0069be00` absolute hits: `0x00553e86`, `0x00554522`, `0x0055452d`, `0x00554542`, `0x0058dd5d`, `0x0058dd6c`, `0x0058e182`, `0x0058e18e`.

## Function / Child Inventory

| Item | UID / path | Role | Current | Recommended |
| --- | --- | --- | --- | --- |
| CopyWindow class | [UID:000039][CopyWindow](by-class/CopyWindow.md) | class declaration and source-quality class owner | `85/86`, blank C++ | `88/90`, declaration C++ |
| CopyWindow file | [UID:0000IH][CopyWindow](by-file/CopyWindow.md) | source root `NexusTK/ui/dialogs/CopyWindow.cpp` | `86/86` | `88/89` |
| CopyWindow method island | [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md) | constructor + primary/secondary callbacks | `86/86`, blank C++ | `88/90`, method C++ |
| vtable data | [UID:0003CV][0x00622e78-0x00622f1c.CopyWindowVtableData](by-memory/0x00622e78-0x00622f1c.CopyWindowVtableData.md) | generated vtable support | `87/92`, blank C++ | score unchanged; add no-code proof |
| `No` label | [UID:0003G5][0x00622f3c-0x00622f44.CopyWindowNoButtonWideString](by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md) | `L"No"` source literal support | `86/91`, blank C++ | score unchanged; source-use/no-code proof |
| `Yes` label | [UID:0003G6][0x00622f44-0x00622f4c.CopyWindowYesButtonWideString](by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md) | `L"Yes"` source literal support | `86/91`, blank C++ | score unchanged; source-use/no-code proof |
| reconnect init helper | [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) | live conditional inline CopyWindow construction | `86/88` | score unchanged; add TextEdit length-query name and inline-construction wording |

## First-Draft C++ Recommendation

### Class page C++

Recommended for `by-class/CopyWindow.md`:

```cpp
class CopyWindow : public AlertPane
{
public:
    CopyWindow();

protected:
    virtual void OnPrimaryButton();
    virtual void OnSecondaryButton();

    [[CHILDREN]]
};
```

Rationale:

- This is declaration-level C++ only, appropriate for a by-class page.
- It matches the existing `AlertPane` base declaration.
- It does not add fields: the observed object state is inherited `AlertPane`/`DialogPane` state.
- It does not add an explicit destructor: the alert-family virtual destructor/deleting wrappers are generated from the base hierarchy and documented under [UID:00010W] / [UID:00010V].

### Exact memory child C++

Recommended for [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md):

```cpp
CopyWindow::CopyWindow()
    : AlertPane(g_pLanguageMan->GetString(0xf1), g_pBackPane, L"Yes", L"No")
{
}

void CopyWindow::OnPrimaryButton()
{
    g_pActiveTextEditPane->SelectAll();
    g_pActiveTextEditPane = 0;
}

void CopyWindow::OnSecondaryButton()
{
    g_pActiveTextEditPane = 0;
}
```

Notes:

- Keep `0xf1` literal-safe unless a project-wide `LanguageStringId` enum or named CopyWindow prompt constant is added.
- Do not add a null guard around `g_pActiveTextEditPane->SelectAll()`; the binary has none.
- If the project standard uses `NULL` instead of `0`, either is acceptable for the first draft; the existing codebase style should decide during implementation.
- If final `LanguageMan` method spelling is standardized as `GetLocalizedString` instead of `GetString`, use that name consistently. The source-quality fact is the `g_pLanguageMan` lookup of id `0xf1`.

### No-code proofs for support children

- `CopyWindowVtableData`: no formal C++ body. Vtables and adjustor thunk slots are generated from the class declaration and inherited virtual destructor layout.
- `CopyWindowNoButtonWideString`: no separate formal C++ body if the constructor emits `L"No"` inline.
- `CopyWindowYesButtonWideString`: no separate formal C++ body if the constructor emits `L"Yes"` inline.
- `ConnectionClosedDialogInitHelper`: no CopyWindow-owned C++ in that helper. Its own body belongs to `ReconnectDialog.cpp`; it may show inline CopyWindow construction in its own future draft, but it should not emit through `CopyWindow`.

## Recommended Target Doc Changes

For `by-class/CopyWindow.md`:

1. Metadata:
   - `COMPLETION:88`
   - `CONFIDENCE:90`
   - keep `CANONICAL_OWNER:0000IH`
   - keep `RECONSTRUCTABLE:TRUE`
   - keep `EMITTER_UIDS:0000IH`
2. Add the class declaration C++ above.
3. Replace "OnAccept/OnCancel" as final source names with:
   - final formal source names: `OnPrimaryButton()` and `OnSecondaryButton()`;
   - behavior aliases: accept/yes and cancel/no.
4. Add a section explaining the raw constructor:
   - `0x005544c0-0x00554513` is not IDA-modeled and has no direct route;
   - it is still a complete source-authored constructor body;
   - live construction is proven by inline duplicate construction inside `0x00553e60`.
5. Replace stale global/resource names:
   - `dword_67A750` -> [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md);
   - `dword_67A740` -> [UID:00028J][g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md);
   - `g_pCopyWindowTextEditPane` -> stale alias for [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md).
6. Replace stale "button table `off_622F44`" wording:
   - primary label is [UID:0003G6] `L"Yes"` at `0x00622f44`;
   - secondary label is [UID:0003G5] `L"No"` at `0x00622f3c`;
   - `off_622F44` is a false pointer interpretation of UTF-16 bytes.
7. Add vtable support:
   - primary vtable `0x00622e7c`;
   - secondary view `0x00622ee4`;
   - tertiary view `0x00622f14`;
   - accept/cancel callback slots at `0x00622ed8` and `0x00622edc`;
   - shared alert-family destructor/adjustor route through [UID:00010W] and [UID:00010V].
8. Preserve rejected alternatives:
   - not `TextEditPane` ownership;
   - not `ReconnectDialog` ownership;
   - not generic `AlertPanes` ownership;
   - not dead/no-code raw bytes;
   - not a class with separate owned global state.

## Recommended Support-Doc Changes

For `by-file/CopyWindow.md`:

- Raise to `88/89`.
- State that the source root should now emit a class declaration and method child C++.
- Correct `off_622F44`/button-table wording to `L"Yes"` / `L"No"`.
- Add the no-direct-route PE scan details for `0x005544c0`.
- Add that `0x0058efa0` in the reconnect helper is a `TextEditPane` text-length/character-count query and not a CopyWindow method.

For `by-memory/0x005544c0-0x0055454b.CopyWindow.md`:

- Raise to `88/90`.
- Add the first-draft method C++ above.
- Correct constructor behavior to:
  - `AlertPane(g_pLanguageMan->GetString(0xf1), g_pBackPane, L"Yes", L"No")`;
  - vptr stores to `0x00622e7c`, `0x00622ee4`, `0x00622f14`.
- Replace `OnAccept` / `OnCancel` source names with `OnPrimaryButton` / `OnSecondaryButton` plus aliases.
- Add fresh PE negative evidence:
  - zero rel32 refs to `0x005544c0`, `0x00554520`, and `0x00554540`;
  - zero absolute VA/RVA dword hits for `0x005544c0`;
  - callback addresses appear only as vtable data refs.

For `by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md`:

- Score can remain `86/88`.
- Add that `0x0058efa0` is best named `TextEditPane::GetTextLength()` / `GetCharCount()` because it returns `word ptr [[this+0x134]+0x0c]`.
- Correct inline CopyWindow argument text to `g_pLanguageMan->GetString(0xf1)`, `g_pBackPane`, `L"Yes"`, `L"No"`.
- Keep owner/emitter under `ReconnectDialog`, with a CopyWindow side-path note only.

For `by-memory/0x00622e78-0x00622f1c.CopyWindowVtableData.md`:

- Score can remain `87/92`.
- Add exact callback-slot note:
  - `0x00622ed8 -> CopyWindow::OnPrimaryButton` behavior alias accept/yes;
  - `0x00622edc -> CopyWindow::OnSecondaryButton` behavior alias cancel/no.
- Add no-code proof: generated from class declaration; do not hand-emit arrays.

For `by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md` and `0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md`:

- Score can remain `86/91`.
- Add no-code/source-use proof: the literals are emitted by the constructor expression; no standalone constant is needed unless the project standard chooses named constants.
- Keep ownership under `CopyWindow`.

For `by-class/TextEditPane.md`, `by-file/TextEditPane.md`, and `by-global/g_pActiveTextEditPane.md`:

- Optional low-risk support sync: add that CopyWindow now uses formal callback names `OnPrimaryButton`/`OnSecondaryButton` while still consuming `g_pActiveTextEditPane`.
- No score change required.

For `by-project-structure/proposed-source-tree.md`:

- Optional support sync only: update the `CopyWindow.cpp` note to say class/method first-draft C++ is now ready under the current 85/85 policy despite the raw standalone constructor.

## Score And Metadata Recommendations

| Path | Current | Recommended | Reason |
| --- | --- | --- | --- |
| `by-class/CopyWindow.md` | `85/86` | `88/90` | class declaration ready; callback source names resolved; stale globals/button-table corrected; raw constructor no longer blocks C++ |
| `by-file/CopyWindow.md` | `86/86` | `88/89` | source-file route strong after class/method C++ and support correction |
| `by-memory/0x005544c0-0x0055454b.CopyWindow.md` | `86/86` | `88/90` | exact method island ready for first-draft C++ |
| `by-memory/0x00622e78-0x00622f1c.CopyWindowVtableData.md` | `87/92` | unchanged | generated-binary vtable support; no-code proof only |
| `by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md` | `86/91` | unchanged | source-use literal support; no standalone code |
| `by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md` | `86/91` | unchanged | source-use literal support; no standalone code |
| `by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md` | `86/88` | unchanged | support wording update only |

## Exact Implementation Checklist For Callback

1. Edit `by-class/CopyWindow.md`.
   - Set `88/90`.
   - Add class declaration C++.
   - Add source-name decisions and rejected alternatives.
   - Correct globals/labels/source placement.
2. Edit `by-file/CopyWindow.md`.
   - Set `88/89`.
   - Correct button-label and global names.
   - Add raw-constructor no-direct-route conclusion and first-draft C++ policy.
3. Edit `by-memory/0x005544c0-0x0055454b.CopyWindow.md`.
   - Set `88/90`.
   - Add method-body first-draft C++.
   - Replace stale constructor argument text.
   - Add fresh PE scan facts and callback source names.
4. Edit `by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md`.
   - Keep score unless implementer finds more evidence.
   - Add `TextEditPane::GetTextLength` / `GetCharCount` inference for `0x0058efa0`.
   - Correct inline CopyWindow construction arguments and retain `ReconnectDialog` ownership.
5. Edit `by-memory/0x00622e78-0x00622f1c.CopyWindowVtableData.md`.
   - Add callback-slot names and no-code proof.
6. Edit `by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md` and `by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md`.
   - Add no-code/source-use proof.
7. Optionally update `by-project-structure/proposed-source-tree.md` CopyWindow note if implementation callback includes project-structure sync.
8. Do not edit `by-memory/-coverage-report.md`; use supervisor-owned coverage text below.
9. Run scoped validators and autogen.

## Exact Pending Coverage Text

Do not edit coverage files during the report pass.

`by-class/-coverage-report.md` replacement row:

```text
- [UID:000039][CopyWindow](by-class/CopyWindow.md) : reconstructable : 88% : very strong : B014 2026-06-19 source-quality pass resolves `CopyWindow` as an `AlertPane` subclass in [UID:0000IH] `CopyWindow.cpp`, raises to `88/90`, emits declaration-level C++ with `OnPrimaryButton`/`OnSecondaryButton` overrides, preserves accept/cancel behavior aliases, rejects stale `g_pCopyWindowTextEditPane` and `TextEditPane`/`ReconnectDialog`/generic-Alert ownership, corrects `g_pLanguageMan`, `g_pBackPane`, `L"Yes"`/`L"No"` label routing, and proves the raw standalone constructor is source-authored despite zero direct call/pointer refs because live reconnect init duplicates the construction inline.
```

`by-file/-coverage-report.md` replacement row:

```text
- [UID:0000IH][CopyWindow](by-file/CopyWindow.md) : reconstructable : 88% : very strong : B014 2026-06-19 source-quality pass raises to `88/89`, keeps `NexusTK/ui/dialogs/CopyWindow.cpp`, routes class declaration and exact method child C++ through `CopyWindow`, corrects stale button-table/global aliases to `g_pLanguageMan`, `g_pBackPane`, `g_pActiveTextEditPane`, `L"Yes"` and `L"No"`, keeps reconnect helper ownership with `ReconnectDialog`, and leaves vtable/string children as no-code generated/source-use support.
```

`by-memory/-coverage-report.md` replacement row for [UID:0001FV]:

```text
    - [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md) 0x005544c0-0x0055454b | class/helper island | CopyWindow : reconstructable : 88% : very strong : B014 2026-06-19 source-quality pass adds first-draft C++ for `CopyWindow::CopyWindow`, `OnPrimaryButton`, and `OnSecondaryButton`; confirms raw constructor bytes/padding, zero direct rel32/VA/RVA route to `0x005544c0`, vtable-only callback refs, `g_pLanguageMan->GetString(0xf1)`, `g_pBackPane`, `L"Yes"`/`L"No"`, `g_pActiveTextEditPane->SelectAll`, and the reconnect helper's live inline construction proof.
```

`by-memory/-coverage-report.md` replacement row for [UID:0001FU] if the support wording is updated:

```text
    - [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md) : reconstructable : 86% : strong : Connection-closed/reconnect post-construction helper; B014 2026-06-19 support sync keeps ReconnectDialog ownership, identifies the CopyWindow side path as inline construction gated by `g_pActiveTextEditPane` and TextEditPane length query `0x0058efa0`, corrects CopyWindow arguments to `g_pLanguageMan->GetString(0xf1)`, `g_pBackPane`, `L"Yes"`, `L"No"`, and preserves caller/callee/touched-global evidence.
```

`by-memory/-coverage-report.md` replacement row for [UID:0003CV]:

```text
    - [UID:0003CV][0x00622e78-0x00622f1c.CopyWindowVtableData](by-memory/0x00622e78-0x00622f1c.CopyWindowVtableData.md) 0x00622e78-0x00622f1c | vtable-data | CopyWindowVtableData : reconstructable : 87% : very strong : CopyWindow vtable data assigned to [UID:000039]; B014 2026-06-19 support sync names primary callback slots `OnPrimaryButton`/`OnSecondaryButton` at `0x00622ed8`/`0x00622edc`, preserves accept/cancel aliases, confirms primary/secondary/tertiary vtable bases and shared AlertPane destructor adjustors, and keeps final C++ blank because vtable bytes are compiler-generated from the class declaration.
```

`by-memory/-coverage-report.md` replacement rows for the two string children if no-code proof is added:

```text
    - [UID:0003G5][0x00622f3c-0x00622f44.CopyWindowNoButtonWideString](by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md) 0x00622f3c-0x00622f44 | string-data | CopyWindowNoButtonWideString : reconstructable : 86% : very strong : CopyWindow UTF-16 `L"No"` secondary/cancel label; B014 2026-06-19 support sync keeps class owner [UID:000039], confirms xrefs from raw and inline CopyWindow construction only, rejects false pointer/table interpretation, and keeps formal C++ blank because the constructor child emits the source-use literal.
    - [UID:0003G6][0x00622f44-0x00622f4c.CopyWindowYesButtonWideString](by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md) 0x00622f44-0x00622f4c | string-data | CopyWindowYesButtonWideString : reconstructable : 86% : very strong : CopyWindow UTF-16 `L"Yes"` primary/accept label; B014 2026-06-19 support sync keeps class owner [UID:000039], confirms xrefs from raw and inline CopyWindow construction only, rejects false `off_622F44` pointer/table interpretation, and keeps formal C++ blank because the constructor child emits the source-use literal.
```

Additional stale support rows discovered in `by-memory/-coverage-report.md`; apply if supervisor is syncing nearby rows:

```text
    - [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md) 0x00553c10-0x00554635 | class method cluster | ConnectionClosedReconnectDialogs : reviewed-container : 88% : very strong : Non-emitting mixed connection/reconnect/CopyWindow address-neighborhood map; exact children now carry source ownership, with `ConnectionClosedDialog`/`ReconnectDialog` code under [UID:0000N0] and the interleaved [UID:0001FV] `CopyWindow` island under [UID:0000IH]; live IDA/PE evidence confirms corrected bounds, function run, singleton clear helpers, destructor wrappers, and mixed-owner no-code aggregate policy.
    - [UID:000269][0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData](by-memory/0x00622d24-0x00622f54.QueueReconnectCopyReadOnlyData.md) 0x00622d24-0x00622f54 | vtable/string-data | QueueReconnectCopyReadOnlyData : reviewed-container : 88% : very strong : Non-emitting mixed Queue/Reconnect/Copy read-only-data map with exact Queue, ConnectionClosedDialog, ReconnectDialog, CopyWindow vtable children and exact string-tail children; B014 2026-06-19 support sync uses its CopyWindow vtable/string child routes and preserves aggregate `RECONSTRUCTABLE:FALSE` / no single owner disposition.
```

## Validation Commands Expected After Implementation

Run from `source-3/project-documentation` after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [000039-CopyWindow-class-source-quality-removed.md](000039-CopyWindow-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result:

- Scoped validators pass.
- Autogen updates `auto-generated/NexusTK/ui/dialogs/CopyWindow.cpp` so it no longer contains only empty markers for the class and method island.
- Vtable and string children may remain empty markers only if their docs include explicit no-code proofs.

## IDA Rename / Type / Comment Recommendations

High confidence:

- Treat `0x005544c0` as `CopyWindow::CopyWindow()`.
- Treat `0x00554520` as `CopyWindow::OnPrimaryButton()` with behavior alias `OnAccept` / "Yes".
- Treat `0x00554540` as `CopyWindow::OnSecondaryButton()` with behavior alias `OnCancel` / "No".
- Use `g_pActiveTextEditPane` for `0x0069be00`.
- Use `g_pLanguageMan` for `0x0067a750`.
- Use `g_pBackPane` for `0x0067a740`.
- Comment `0x00622f44` as UTF-16 `L"Yes"`; reject `off_622F44`.
- Comment `0x00622f3c` as UTF-16 `L"No"`.
- Comment `0x00622e7c`, `0x00622ee4`, and `0x00622f14` as CopyWindow vtable views.

Medium confidence:

- Name `0x0058efa0` `TextEditPane::GetTextLength()` or `TextEditPane::GetCharCount()`. The behavior is proven; exact original spelling is not.

No rename / keep as support:

- Do not rename `0x00553e60` as a CopyWindow method. It is a reconnect/connection-closed init helper with a CopyWindow side path.
- Do not create standalone source names for the vtable bytes or button-string child pages unless the project adopts explicit named constants.

## Open Questions And Closure

- Exact localized text for string id `0xf1`: not resolved in this pass. Evidence checked: `str-res-localized-strings.md` records the resource format and partial id mapping but not id `0xf1`. Best direction: keep numeric id `0xf1` in first-draft C++ and document "CopyWindow prompt string id." This does not block C++ because the binary uses a numeric language-table lookup.
- Exact original spelling of `TextEditPane::GetTextLength` / `GetCharCount`: not proven. Evidence checked: docs and fresh disassembly. Best direction: use descriptive name in support docs; not needed for CopyWindow class C++ unless the reconnect helper gets its own method draft later.
- Direct call route to `CopyWindow::CopyWindow`: negative. Evidence checked: rel32, absolute VA, and RVA scans. Best direction: document no direct route and inline construction proof; do not lower owner/emitter or block C++.

No remaining open question blocks class-level or exact-child first-draft C++ under the current combined-score/emitter gate.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/000039-CopyWindow-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"000039"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000039-CopyWindow-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/000039-CopyWindow-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000039"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
