** TARGET-REPORT-UID:00049P **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID00049P ExchangeDialogConstructor Source-Quality Report

Report timestamp: 2026-06-29T21:45:00-04:00  
Agent: B005  
Assignment: `B005-report-00049P-ExchangeDialogConstructor-source-quality-20260629`  
Original mode: report-only research; no leases; no by-* edits; no generated-output edits; no subagents.  
Implementation callback update: 2026-06-29 B005 applied the supervisor-accepted report details to the target/support by-* docs under short leases, ran scoped validators, and updated this checklist/ledger for supervisor verification.

## Finalized Report / Current Recommendation

Promote [UID:00049P] `by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md` from a non-emitting exact child to a first-draft emitted constructor through [UID:00004R] `ExchangeDialog`.

Recommended target metadata after implementation:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:00004R
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00004R
EMITTER_POSITION_OPTIONAL:
```

The old blocker was real when B001 created the exact child, but it is now stale. Current MCP evidence resolves the exact range, callers, resource literals, vtable/control construction stores, packet fields, local/remote list construction, local money edit control, remote money display, ready/offer state fields, and the class/file output route. Accepted sibling reports now also stabilize the source-facing names used by the constructor: `m_exchangeSessionId`, `m_localOfferPending`, `m_localReadyConfirmed`, `m_peerReadyConfirmed`, `m_localExchangeAmount`, `m_amountDecreasePending`, `m_timerHandler`, `SubmitExchangeAmount`, `GetControl`, `SetActiveControl`, `SetCurrentControl`, and the control ids `1`, `2`, `3`, `5`, `6`, `8`, and `9`.

This is not a rare no-improvement/no-code case. Leaving `EMITTER_UIDS` blank would preserve an empty coverage gap even though the constructor is an exact, live, class-owned function and now clears the source-readiness gate.

## Current Target State

- Target UID: `00049P`
- Target path: `by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md`
- Current metadata: `84/86`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Pre-callback queue state: `auto-generated/-ag-research-tracker.md` row reported `84/86`, combined `85.0`, reconstructable `true`, reports `0`.
- Pre-callback generated state: `auto-generated/-ag-coverage-report-by-memory.md` listed UID00049P as non-emitting with no generated output file, and `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` had sibling methods but no constructor body.
- Current target prose says C++ should remain blank because resource/control field names and final declarations were not resolved. This report resolves those named blockers enough for first-draft emission.

## Evidence Checked

Project documents checked:

- Target page [UID:00049P] `by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md`.
- Source owner/route pages: [UID:00004R] `by-class/ExchangeDialog.md`, [UID:0000J9] `by-file/ExchangeDialog.md`, and [UID:00014K] `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`.
- Support pages: [UID:00004S] `ExchangeItemListPane`, [UID:00004T] `ExchangeMoneyEditControlPane`, [UID:0003NG] `ExchangeDialogResourceStrings`, [UID:0001RA] `exchange-dialog-resources`, [UID:00025A] `ExchangeItemReadOnlyData`, and sibling method targets UID00049Q through UID00049Y.
- Generated source: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`, refreshed at validator command id `000000001210`.
- Generated reports: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md`.

Prior report/search audit:

- Searched for `00049P`, `0x004ac8a0`, `ExchangeDialogConstructor`, `ExchangeDialog constructor`, `DLGEXC1`, `ExchangeItemListPane`, `ExchangeMoneyEditControlPane`, sibling UIDs `00049Q` through `00049Y`, and the owner/source family.
- No direct executed report for UID00049P was found; the tracker also reports `reports 0`.
- Relevant prior reports used as leads, not authority: B001 `00014K-ExchangeDialog-empty-emitter-source-quality.md`, B002 `00025A-ExchangeItemReadOnlyData-post-migration.md`, B006 `00049V-ExchangeDialogSubmitExchangeAmount-source-quality.md`, B012 `00049S-ExchangeDialogUpdateButtonStates-source-quality.md`, plus accepted sibling target/support pages for UID00049Q/R/S/T/U/V/W/Y/Z.

MCP availability:

- MCP was available. No `PAUSED_MCP_*` condition applies.
- Initial `idb_list` returned no sessions, but the MCP listener was live on `127.0.0.1:13337`. Normal MCP `idb_open` was used for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Session opened as `B005_00049P_20260629`.
- `server_health` returned `status:ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- One `xrefs_to` call and two `get_bytes` attempts used obsolete parameter names first; corrected schema calls succeeded. These were tool-schema retries, not MCP outage/busy conditions.

## Claim And Incorporation Ledger

| Claim | Evidence | Destination | State |
| --- | --- | --- | --- |
| C-001 exact function range is `0x004ac8a0-0x004ad0aa`, IDA start `sub_4AC8A0`, size `0x80a` | Current `lookup_funcs` and `entity_query`; `0x004ad0aa` not a function, successor `0x004ad0b0` | Target status/MCP evidence | applied |
| C-002 constructor has live callers and is not a retained duplicate | `xrefs_to 0x004ac8a0` from `0x005086c0` and `0x00513a77`; both allocate `0x27c` and pass packet pointer | Target callsite evidence; aggregate child row | applied |
| C-003 resource literals are resolved as UTF-16 `DLGEXC1.PAL`, `DLGEXC1.EPF`, and `%s(%s)` | `get_bytes 0x0061a304 size 64`; constructor xrefs at `0x004ac9d2`, `0x004ac9e2`, `0x004acf8a`, `0x004acb40` | Target behavior; resource-string support already present | applied |
| C-004 ExchangeDialog and child control vtables are constructor-installed | xrefs to `0x00619d2c/8c/bc`, `0x00619dc8/50/80`, `0x0061a264/2cc/2fc` from constructor | Target control construction matrix; by-class support note | applied |
| C-005 packet parse and fields are source-ready | MCP disasm/decompile: session id from packet `+2`, partner name length `+6`, name bytes `+7`, partner amount from `packet+7+len` | Target behavior and C++ block | applied |
| C-006 control ids and layout are resolved | Constructor disasm: buttons, labels, list controls, local money edit, remote money text; sibling methods consume ids `1/2/3/5/6/8/9` | Target behavior; by-class ExchangeDialog controls section | applied |
| C-007 ready/money state fields are resolved enough for first draft | Accepted sibling pages for UID00049S/V/W/Y and class notes define `+0x270..+0x278` names | Target C++ block; class support update | applied |
| C-008 direct owner remains `00004R` and source route remains `00004R -> 0000J9` | Receiver is ExchangeDialog, generated source already emits siblings through `ExchangeDialog.cpp` | Target metadata; by-class/by-file support | applied |
| C-009 first-draft C++ is now justified | Current evidence plus accepted helper/control/source names clear combined score above 85 after recommended raise | Target formal C++ | applied |
| C-010 rejected alternatives are documented | No-owner, file-direct owner, resource owner, item-list/money-control owners, covered-by/no-code, and blank-emitter alternatives fail evidence | Target heuristic/ownership sections | applied |
| C-011 formal constructor source shape is VC-era first draft | Report revision removes the prior C++17 array-size helper, C++11 empty aggregate initialization, and unexplained local wrapper helpers; local label/status data flow is expressed through documented `g_activeUserStatusPane` accessors/field surfaces | Target formal C++ and source-shape caveats | applied |

## IDA MCP Facts

### Function Boundary

`lookup_funcs` results:

| Address | Result |
| --- | --- |
| `0x004ac89a` | Not a function; prior exception-handler body ends before constructor. |
| `0x004ac8a0` | `sub_4AC8A0`, size `0x80a`. |
| `0x004ad0a9` | Inside `sub_4AC8A0`. |
| `0x004ad0aa` | Not a function; exclusive end/alignment start. |
| `0x004ad0b0` | `sub_4AD0B0`, size `0x11a`, UID00049Q successor. |

`entity_query functions 0x004ac880-0x004ad0c0` returned only:

- `0x004ac8a0 sub_4AC8A0 size 0x80a`
- `0x004ad0b0 sub_4AD0B0 size 0x11a`

No split, merge, rename, or range change is recommended.

### Callers

- `sub_513A20`: validates packet byte `+1`, allocates `0x27c`, calls `sub_4AC8A0(v1, Block)`, returns success.
- `sub_507C90`: jump-table case `66`, validates packet byte `+1`, allocates `0x27c`, calls `sub_4AC8A0(this, packet)`, returns success.

Both callers prove live construction, expected object size, and packet-fed constructor semantics. This rejects a covered-by/no-route disposition.

### Resources And Strings

`xrefs_to`:

- `0x0061a304`: constructor xref `0x004ac9d2`.
- `0x0061a31c`: constructor xrefs `0x004ac9e2` and `0x004acf8a`.
- `0x0061a334`: constructor xref `0x004acb40`.

IDA `get_string` truncates the first two UTF-16 literals to `D` and `DL`, so raw bytes are the authoritative string proof here. Corrected `get_bytes` over `0x0061a304` returned:

```text
44 00 4c 00 47 00 45 00 58 00 43 00 31 00 2e 00
50 00 41 00 4c 00 00 00 44 00 4c 00 47 00 45 00
58 00 43 00 31 00 2e 00 45 00 50 00 46 00 00 00
25 00 73 00 28 00 25 00 73 00 29 00 00 00 00 00
```

Decoded: `DLGEXC1.PAL\0DLGEXC1.EPF\0%s(%s)\0\0`.

### Vtables And Control Construction

Constructor stores:

- ExchangeDialog vtable views: `0x00619d2c`, `0x00619d8c`, `0x00619dbc` at `0x004ac8f4`, `0x004ac8fa`, `0x004ac904`.
- First ExchangeItemListPane instance: vtable stores `0x00619dc8`, `0x00619e50`, `0x00619e80` at `0x004acbef`, `0x004acbf5`, `0x004acbff`.
- Second ExchangeItemListPane instance: same vtable stores at `0x004acd9c`, `0x004acda2`, `0x004acdac`.
- ExchangeMoneyEditControlPane instance: vtable stores `0x0061a264`, `0x0061a2cc`, `0x0061a2fc` at `0x004accd3`, `0x004accd9`, `0x004acce3`.

Constructor layout facts from bounded disassembly:

| Control/order | Evidence | Source-facing disposition |
| --- | --- | --- |
| background | `DLGEXC1.EPF/PAL`, rect `(0,0,451,371)`, allocation `0x14c` | `EPFImageControlPane`, `LoadDialogBackground(L"DLGEXC1.EPF")` |
| control `1` | button rect `(84,335,147,359)`, text/resource id `14` | confirm/ready/OK button |
| control `2` | button rect `(188,335,251,359)`, text/resource id `36` | add-item button |
| control `3` | button rect `(292,335,355,359)`, text/resource id `22` | cancel button |
| control `4` | static local player label rect `(30,60,197,72)` | display label using `%s(%s)` |
| control `5` | first `ExchangeItemListPane`, wrapper rect `(30,110,222,283)` | local offered-item list |
| control `6` | `ExchangeMoneyEditControlPane`, rect `(73,295,197,307)`, initial text `L"0"` | local money edit |
| control `7` | static partner label rect `(241,60,408,72)` | remote player label |
| control `8` | second `ExchangeItemListPane`, wrapper rect `(241,110,432,283)` | remote offered-item list |
| control `9` | static text rect `(284,295,408,307)`, initial text `L"0"` | remote money display |
| non-critical labels | rects `(82,83,210,95)` and `(295,83,423,95)` | local/partner amount labels |

### Constructor Behavior

Current `analyze_function 0x004ac8a0` reports IDA prototype `int __thiscall(int this, int)`, size 2058, 71 basic blocks, cyclomatic complexity 3. The decompilation is truncated, so the bounded disassembly is the primary body evidence.

Important behavior:

- Base/inherited setup call: `sub_49D8A0(this, word_60DB20, 9, 1)`, source-facing `DialogPane(L"", 9, true)`.
- Packet parse:
  - `m_exchangeSessionId` from packet `+2` via 32-bit big-endian read.
  - partner name byte length at packet `+6`.
  - counted narrow name bytes from packet `+7`, converted with `MultiByteToWideChar(CP_ACP, 0, ...)` into a 64-wide-character buffer.
  - partner amount/value from `packet + 7 + nameLength` via 16-bit big-endian read.
- Resource/control setup:
  - fixed 451x371 bounds.
  - `DLGEXC1.PAL` and `DLGEXC1.EPF` are used for the background; `DLGEXC1.EPF` is loaded again near `0x004acf8a`.
  - local label is formatted with `%s(%s)` from local player/status/profile data.
  - local and remote item lists are both `ExchangeItemListPane` using the `ListPane(sizeof(ExchangeItemListRow), 8, 0x9c, 0x18, 0, 1, 1)` shape established by UID00014Q.
  - local money edit control is `ExchangeMoneyEditControlPane`, control id `6`, initial text `L"0"`.
  - remote money display is static text/control id `9`, initial text `L"0"`.
- End setup:
  - normalizes and submits local money when active control id is `6` and the money edit active byte is set; the logic matches UID00049Y's focus-leave normalization and calls UID00049V `SubmitExchangeAmount`.
  - calls the dialog mode/control selection helpers with arguments `2`, `1`, and `3`.
  - clears `m_localOfferPending`, `m_localReadyConfirmed`, `m_peerReadyConfirmed`, `m_localExchangeAmount`, and `m_amountDecreasePending`.
  - attaches/shows the dialog through `g_pDefaultParent`/`g_pScreenPane` paths.

## Positive Evidence Summary

- UID00049P is an exact, live, modeled constructor, not a raw retained duplicate.
- Both callers allocate `0x27c` and pass the server packet pointer to this constructor.
- The resource names are raw-byte proven, and their package provenance is already documented by the resource support page.
- All constructed child controls have bounded coordinates, class routes, and stable control ids used by emitted sibling methods.
- The formerly unresolved ready/money state field names are now shared by accepted first-draft sibling pages.
- The source route is already proven by generated sibling output: [UID:00004R] `ExchangeDialog` emits into [UID:0000J9] `ExchangeDialog.cpp`.
- The constructor's score can be raised above the `>85` code-entry gate without inventing a new owner, a new file route, or a broad aggregate emitter.

## Negative Evidence Summary

- No evidence supports `CANONICAL_OWNER:NONE`: the receiver, fields, callers, controls, and packet semantics are ExchangeDialog-specific.
- No evidence supports direct file ownership by [UID:0000J9] instead of class ownership. The file is the output route; the semantic owner is the `ExchangeDialog` class.
- `ExchangeItemListPane` and `ExchangeMoneyEditControlPane` are constructed dependencies. They own their own methods/vtables, but they do not own the outer dialog constructor body.
- The resource-string child and resource package docs are dependencies, not code owners.
- A covered-by marker is not valid: no sibling emitted method covers background/control construction, packet partner-label setup, and initial state.
- Keeping blank C++ is now weaker than emitting a first draft. Remaining uncertainty is original helper/member spelling for local profile/amount formatting and show/attach helpers, which is a confidence cap rather than a blocker.

## Heuristic / Inference Reanalysis

The B001 split disposition capped UID00049P at `84/86` because the constructor was large and the field/control/source declarations were not then final. That was a conservative and correct creation-time decision. The current state has changed:

- Sibling methods now emit and lock in the exchange state field names and packet helper names.
- `ExchangeItemListPane` now documents `ExchangeItemListRow`, the list constructor shape, and the two live list construction stores.
- `ExchangeMoneyEditControlPane` now documents local money control id `6`, text read/set helpers, and active-byte naming used by UID00049Y.
- `ExchangeDialogResourceStrings` and the resource package page resolve the `DLGEXC1` literals.
- Current generated `ExchangeDialog.cpp` already uses the same first-draft style expected here: readable helper names, `PacketRead*` helpers, `GetControl`, `SetText`, `SetEnabled`, `ReadText`, `SubmitExchangeAmount`, and direct class methods.

Therefore the old blocker has been reduced to source-name polish. The workflow treats that as a score cap, not as a reason to preserve a blank emitter when behavior, ownership, route, and dependencies are otherwise bounded.

Rejected alternatives:

| Alternative | Why rejected |
| --- | --- |
| Keep blank `EMITTER_UIDS` and blank C++ | The exact function is live, class-owned, and now has resolved control/resource/state evidence. |
| Emit through [UID:0000J9] directly | File root is output routing, not direct semantic ownership for an `ExchangeDialog` constructor. |
| Assign to `ExchangeItemListPane` or `ExchangeMoneyEditControlPane` | Those classes own constructed children only, not the outer packet-fed dialog construction. |
| Assign to resource docs | Resources are constructor inputs only. |
| Create a covered-by marker | No existing emitted body covers construction. |
| Split the constructor | Current IDA shows one modeled function with only alignment at the exclusive end; no internal function start or independent raw body is proven. |

## Ranked Ownership

1. [UID:00004R] `ExchangeDialog`: accepted. The receiver is the dialog object, the function stores ExchangeDialog vtables, initializes ExchangeDialog fields, constructs ExchangeDialog controls, and is called as the constructor from packet dispatch code.
2. [UID:0000J9] `ExchangeDialog` file: accepted as source route only. It already emits sibling `ExchangeDialog` methods and private exchange controls.
3. [UID:00004S] `ExchangeItemListPane`: dependency only. The constructor creates two list instances but does not transfer ownership of the outer body.
4. [UID:00004T] `ExchangeMoneyEditControlPane`: dependency only. The constructor creates local money edit control id `6`.
5. Resource/string pages: dependency only.
6. `NONE`: rejected because the function is live project code with a direct class receiver.

## First-Draft C++ Recommendation

Eligible for first-draft C++: yes.

Recommended formal `RECONSTRUCTION_CPP CODE` insertion text for UID00049P:

Source-shape audit for this revision:

- No C++17-style helpers are used. The previous array-size helper text is replaced by explicit fixed counts, matching the style already used in older generated/source-facing docs.
- Empty aggregate initialization is written as `{0}` rather than `{}`.
- The prior local label and local numeric display wrapper helpers are removed from the formal block. The local label is now expressed as the documented `g_activeUserStatusPane` copy-out data flow plus the `%s(%s)` format literal, and the local numeric display uses a named first-draft field surface for `g_activeUserStatusPane + 0x280`.
- `g_activeUserStatusPane->CopyNameLineA(...)` and `CopyNameLineB(...)` are still source-facing inferred accessor names, but they are directly backed by [UID:0001NN] evidence: constructor callsites `0x004acb1d` and `0x004acb2d` pass the active `UserStatusPane` receiver, and the accessors copy the `+0x0fc` and `+0x1fc` 64-wide-character fields.
- `m_statusClassByte` is a temporary first-draft field surface for `g_activeUserStatusPane + 0x280`, documented by [UID:0001WF] `UserStatusPaneSummaryFields` as a layout-mode-dependent status/class byte. It is preferable to the previous magic helper because the formal code now shows the actual singleton/field dependency.
- The partner-name conversion keeps the observed counted narrow copy, `CP_ACP` conversion into a 64-wide-character buffer, and explicit NUL termination. The exact compiler range-check source shape is not proven, so the formal block uses a conservative explicit clamp before termination instead of emitting compiler/runtime-check scaffolding.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ExchangeDialog::ExchangeDialog(const unsigned char *packet)
    : DialogPane(L"", 9, true)
{
    m_exchangeSessionId = PacketReadUInt32BE(packet + 2);

    unsigned int partnerNameLength = PacketReadByte(packet + 6);
    char partnerNameBytes[256] = {0};
    memcpy(partnerNameBytes, packet + 7, partnerNameLength);
    partnerNameBytes[partnerNameLength] = 0;

    wchar_t partnerName[64] = {0};
    int partnerNameChars = MultiByteToWideChar(CP_ACP, 0, partnerNameBytes,
                                               partnerNameLength,
                                               partnerName, 64);
    if (partnerNameChars < 0) {
        partnerNameChars = 0;
    }
    if (partnerNameChars >= 64) {
        partnerNameChars = 63;
    }
    partnerName[partnerNameChars] = 0;

    unsigned int partnerDisplayValue =
        PacketReadUInt16BE(packet + 7 + partnerNameLength);

    AddControl(new EPFImageControlPane(MakeRect(0, 0, 451, 371),
                                       0x14c,
                                       L"DLGEXC1.EPF",
                                       L"DLGEXC1.PAL"));
    AddImageButton(1, Rect(84, 335, 147, 359), 14);
    AddImageButton(2, Rect(188, 335, 251, 359), 36);
    AddImageButton(3, Rect(292, 335, 355, 359), 22);

    wchar_t localName[64] = {0};
    wchar_t localStatusLine[64] = {0};
    wchar_t localLabel[128] = {0};
    g_activeUserStatusPane->CopyNameLineA(localName, 64);
    g_activeUserStatusPane->CopyNameLineB(localStatusLine, 64);
    swprintf_s(localLabel, 128, L"%s(%s)", localName, localStatusLine);
    AddControl(new StaticTextControlPane(Rect(30, 60, 197, 72), localLabel));

    AddControl(5, new ExchangeItemListPane(), Rect(30, 110, 222, 283));

    ExchangeMoneyEditControlPane *moneyEdit =
        new ExchangeMoneyEditControlPane(Rect(73, 295, 197, 307), L"0");
    AddControl(6, moneyEdit);

    AddControl(new StaticTextControlPane(Rect(241, 60, 408, 72), partnerName));
    AddControl(8, new ExchangeItemListPane(), Rect(241, 110, 432, 283));
    AddControl(9, new StaticTextControlPane(Rect(284, 295, 408, 307), L"0"));

    wchar_t amountText[32];
    swprintf_s(amountText, 32, L"%d",
               (int)g_activeUserStatusPane->m_statusClassByte);
    AddControl(new StaticTextControlPane(Rect(82, 83, 210, 95), amountText));

    swprintf_s(amountText, 32, L"%d", partnerDisplayValue);
    AddControl(new StaticTextControlPane(Rect(295, 83, 423, 95), amountText));

    LoadDialogBackground(L"DLGEXC1.EPF");

    if (m_activeControlId == 6 && moneyEdit->m_editActive) {
        wchar_t localAmountText[10];
        moneyEdit->ReadText(localAmountText, 10);

        unsigned int amount = 0;
        if (_wtol(localAmountText) > 0) {
            amount = (unsigned int)_wtol(localAmountText);
        }

        if (amount == 0) {
            moneyEdit->SetText(L"0");
        }

        SubmitExchangeAmount(amount);
    }

    SetDialogMode(2);
    SetActiveControl(1);
    SetCurrentControl(3);

    m_localOfferPending = 0;
    m_localReadyConfirmed = 0;
    m_peerReadyConfirmed = 0;
    m_localExchangeAmount = 0;
    m_amountDecreasePending = 0;

    Rect bounds(0, 0, 451, 371);
    SetFrameRect(&bounds, 0, 0, g_pDefaultParent);
    OnShow(g_pScreenPane, 0);
    Show();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

First-draft caveats that should remain in target prose:

- The local player label is no longer modeled as a magic helper. Current support docs show `g_activeUserStatusPane` as the receiver, `CopyNameLineA` copies the `+0x0fc` line, `CopyNameLineB` copies the `+0x1fc` line, and the constructor formats those two lines with the raw-byte-proven `%s(%s)` literal.
- The local numeric display field `m_statusClassByte` is a temporary first-draft member name for byte `g_activeUserStatusPane + 0x280`. [UID:0001WF] describes it as a layout-mode-dependent status/class byte, not a proven "gold" or "money" field. The constructor formats it with `L"%d"` for the local label opposite the packet-supplied partner display value.
- The partner-name conversion source shape remains a confidence cap. The binary proves counted narrow copy, `MultiByteToWideChar(CP_ACP, ...)` into a 64-wide buffer, a range-checked terminator write, and a NUL terminator. The formal block uses explicit bounds/clamp before termination because the exact source-level guard versus compiler-instrumented range-check form is not recoverable from current evidence.
- `ExchangeMoneyEditControlPane(Rect, const wchar_t *)`, `EPFImageControlPane`, `AddImageButton`, `AddControl`, `LoadDialogBackground`, `SetFrameRect`, `OnShow`, and `Show` are first-draft source-facing helper surfaces consistent with existing generated UI constructor style. Exact historic overload spellings remain final-audit confidence caps.
- The formal body intentionally uses existing accepted names from sibling emitted code for fields and callbacks. Do not replace them with `sub_` names or raw offsets.

## Score And Metadata Recommendation

Current target metadata:

```text
COMPLETION:84
CONFIDENCE:86
CANONICAL_OWNER:00004R
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
```

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:00004R
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00004R
```

Rationale:

- Completion rises because the constructor has exact range/callers/resources/control construction, and the previous resource/control/state blockers are now resolved.
- Confidence remains below 90 because `CopyNameLineA/B`, `m_statusClassByte`, exact UI constructor overloads, the show/attach helper spellings, and the source-level form of the partner-name range check are still inferred source-facing names/shapes rather than original symbol proof.
- Combined score after recommendation is `88.5`, clearing the `>85` C++ gate for a reconstructable child with a valid nonblank emitter route.

## Recommended Target Doc Changes

Target path: `by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md`

- Change metadata to `88/89`, keep `CANONICAL_OWNER:00004R`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00004R`, leave `EMITTER_POSITION_OPTIONAL` blank.
- Populate formal `RECONSTRUCTION_CPP CODE` with the constructor block above.
- Replace the current no-code disposition with an emission disposition: first-draft constructor through [UID:00004R] into [UID:0000J9].
- Add current MCP evidence:
  - session `B005_00049P_20260629`
  - exact function range and successor boundary
  - caller allocation/callsite evidence
  - raw-byte proof for `DLGEXC1.PAL`, `DLGEXC1.EPF`, `%s(%s)`
  - vtable/control construction stores
  - control layout/id matrix
  - end-state initialization and money-normalization call to `SubmitExchangeAmount`.
- Preserve boundary note `0x004ad0aa-0x004ad0b0` alignment before UID00049Q.

## Recommended Support Doc Changes

Support path: `by-class/ExchangeDialog.md`

- Update UID00049P method row from non-emitting `84/86` to first-draft emitting `88/89`.
- Add a constructor note with control layout ids, resource strings, packet fields, and end-state initialization.
- Add the revised source-shape caveats: local label formatting flows through `g_activeUserStatusPane->CopyNameLineA/B`, local numeric display reads the temporary `m_statusClassByte` surface for `g_activeUserStatusPane + 0x280`, and partner-name termination uses a conservative explicit clamp instead of compiler/runtime-check scaffolding.

Support path: `by-file/ExchangeDialog.md`

- Update the `ExchangeDialog.cpp` contents/source-route note to say UID00049P now emits `ExchangeDialog::ExchangeDialog(const unsigned char *packet)`.
- Note that this resolves the only remaining blank constructor gap in the current generated `ExchangeDialog.cpp` sibling cluster.

Support path: `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`

- Update the UID00049P child row from non-emitting `84/86` to first-draft emitting `88/89`.
- Add a change note tying the promoted constructor to current MCP session `B005_00049P_20260629`.

Already-present support, no edit required unless supervisor wants additional cross-links:

- [UID:0003NG] `ExchangeDialogResourceStrings` already covers `DLGEXC1.PAL`, `DLGEXC1.EPF`, and `%s(%s)`.
- [UID:0001RA] `exchange-dialog-resources` already covers packaged `DLGEXC1.EPF/PAL` provenance.
- [UID:00004S] `ExchangeItemListPane` already covers row layout and list constructor shape.
- [UID:00004T] `ExchangeMoneyEditControlPane` already covers local money edit control id `6` and text helper behavior.
- [UID:00049S/V/W/Y] already cover state fields, amount-submit, amount setter, and money focus normalization.

## Validators And Generated Refresh

Implementation callback validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00049P-ExchangeDialogConstructor-source-quality-removed.md](00049P-ExchangeDialogConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Results:

| File | command_id | command_timestamp | Exit | ok | Generated refresh / notes |
| --- | --- | --- | --- | --- | --- |
| `by-memory\0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md` | `000000001256` | `2026-06-29T21:40:04-04:00` | `0` | `1` | `generated_refresh: completed`; generated refresh command id/timestamp matched `000000001256` / `2026-06-29T21:40:04-04:00`; validator updated UID00049P metadata, registry hash/code state, `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and projected stats. |
| `by-class\ExchangeDialog.md` | `000000001257` | `2026-06-29T21:40:20-04:00` | `0` | `1` | `generated_refresh: deferred`; `stats_incremental_noop` only for this file in generated stats lists. |
| `by-file\ExchangeDialog.md` | `000000001258` | `2026-06-29T21:40:27-04:00` | `0` | `1` | `generated_refresh: deferred`; reported `missing_ref_uid 0003U3` on a pre-existing B004 support link. The target file `by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md` exists with `UID:0003U3`, so this was left as unrelated validator registry state rather than hand-editing validator state or unrelated docs. |
| `by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md` | `000000001259` | `2026-06-29T21:40:57-04:00` | `0` | `1` | `generated_refresh: deferred`; `auto-generated/-ag-coverage-report-by-memory.md` and `auto-generated/-ag-research-tracker.md` headers refreshed to command `000000001259`. |

Generated-output checks after validation:

> Executable block R002 was removed from this report and preserved verbatim in [00049P-ExchangeDialogConstructor-source-quality-removed.md](00049P-ExchangeDialogConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Observed generated result:

- `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` header is `validator-command-id: 000000001258`, `validator-refreshed-at: 2026-06-29T21:40:27-04:00`, which is newer than the target validator command `000000001256`. Lines `7-8` contain `UID:00049P` and `ExchangeDialog::ExchangeDialog(const unsigned char *packet)`. No UID00049P empty marker, `non-emitting`, `No reconstruction`, `TODO`, `std::size`, `FormatLocalExchangePlayerLabel`, or `GetLocalExchangeAmountForDisplay` text was found in that generated file.
- `auto-generated/-ag-coverage-report-by-memory.md` line `911` shows UID00049P with `emits_code:true`, reconstructable, `88%`, and the updated first-draft emitting item summary.
- `auto-generated/-ag-research-tracker.md` line `2718` shows UID00049P at `88/89`, combined `88.5`, reconstructable `true`, report count `0` pending supervisor execution.
- UID00049P is no longer listed in the generated low-score project stats rows; the target validator reported `stats_row_remove` for low-completion, low-confidence, low-both, and by-memory reconstructable generated lists.

Lease result:

- Read current lease report before editing; no active relevant ExchangeDialog lease was present.
- Lease command succeeded for the four by-* docs: target UID00049P, `by-class/ExchangeDialog.md`, `by-file/ExchangeDialog.md`, and aggregate UID00014K.
- Cleanup `unlease` command after validation reported `Rejected[No active lease]` for all four files, meaning the short leases had already expired before cleanup. The follow-up current lease report contains no active B005 rows; only stale expired Supervisor rows from 2026-06-18 remain.

## Implementation Tracking Checklist

- [x] Update target UID00049P metadata to `88/89`, `EMITTER_UIDS:00004R`. Proof: `by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md` metadata now has `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00004R`; validator `000000001256` reported `completion_update`, `confidence_update`, and registry update for UID00049P.
- [x] Insert the revised formal constructor C++ block exactly as recommended or with only supervisor-approved helper spelling refinements; preserve the VC-era source shape with explicit counts, `{0}` initialization, no C++17 array-size helper, and no unexplained local wrapper helpers. Proof: target formal `RECONSTRUCTION_CPP CODE` now contains `ExchangeDialog::ExchangeDialog(const unsigned char *packet)` with explicit counts, `{0}` initialization, direct `g_activeUserStatusPane->CopyNameLineA/B`, `m_statusClassByte`, and the conservative partner-name clamp; generated `ExchangeDialog.cpp` lines `7-8` show UID00049P and constructor output.
- [x] Replace stale no-code/blocker prose on the target with current MCP-backed first-draft emission rationale, including the `g_activeUserStatusPane` label/status data flow and partner-name buffer termination caveat. Proof: target `Behavior`, `MCP Evidence`, `Resource Bytes And Controls`, `C++ / No-Code Disposition`, and `Changes` sections now document B005 session `B005_00049P_20260629`, packet/resource/control/vtable facts, rejected alternatives, and source-shape caveats.
- [x] Update [UID:00004R] `ExchangeDialog` method/control notes. Proof: `by-class/ExchangeDialog.md` method row now states UID00049P is first-draft emitting `88/89`; `Data And Controls` adds constructor packet fields, resources, control layout, and caveats; `Changes` has the 2026-06-30 B005 callback note.
- [x] Update [UID:0000J9] `ExchangeDialog` file route/source contents. Proof: `by-file/ExchangeDialog.md` evidence basis includes B005 session `B005_00049P_20260629`; `Packet And Control Model` now says UID00049P emits `ExchangeDialog::ExchangeDialog(const unsigned char *packet)` through `ExchangeDialog.cpp`; `Changes` has the 2026-06-30 B005 callback note.
- [x] Update [UID:00014K] aggregate child row/change note. Proof: `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md` confidence/status text includes UID00049P among first-draft routed children, the UID00049P covered-range row is `88/89` first-draft emitting, and `Changes` has the B005 callback note.
- [x] Mark already-present support pages with proof. Proof: [UID:0003NG] `by-memory/0x0061a304-0x0061a344.ExchangeDialogResourceStrings.md` item summary covers `DLGEXC1.PAL`, `DLGEXC1.EPF`, and `%s(%s)`; [UID:0001RA] `by-resource/exchange-dialog-resources.md` records package/provenance and xrefs for `0x0061a304`, `0x0061a31c`, and `0x0061a334`; [UID:00004S] `ExchangeItemListPane` and UID00014Q record `ExchangeItemListRow` and `ListPane(sizeof(ExchangeItemListRow), 8, 0x9c, 0x18, 0, 1, 1)`; [UID:00004T] `ExchangeMoneyEditControlPane` records local money control id `6`, `ReadText`, `SetText`, and `m_editActive`; UID00049S/V/W/Y pages record state fields, submit, setter, and focus normalization.
- [x] Run scoped validators on target and touched support docs. Proof: commands `000000001256`, `000000001257`, `000000001258`, and `000000001259` all exited `0` with `ok:1`; exact command/timestamp details are recorded above.
- [x] Confirm generated `ExchangeDialog.cpp` includes UID00049P constructor output. Proof: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` header `validator-command-id: 000000001258`, refreshed `2026-06-29T21:40:27-04:00`, contains UID00049P at line `7` and `ExchangeDialog::ExchangeDialog(const unsigned char *packet)` at line `8`.
- [x] Confirm generated coverage/tracker rows reflect emits/source route and recommended score. Proof: `auto-generated/-ag-coverage-report-by-memory.md` line `911` has UID00049P `emits_code:true`, reconstructable, `88%`, first-draft emitting summary; `auto-generated/-ag-research-tracker.md` line `2718` has `88/89`, combined `88.5`, reconstructable `true`; project stats no longer list UID00049P in low-score generated rows.

## Changed Files In This Pass

Implementation callback changed files:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/00049P-ExchangeDialogConstructor-source-quality.md`
- `source-3/project-documentation/by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md`
- `source-3/project-documentation/by-class/ExchangeDialog.md`
- `source-3/project-documentation/by-file/ExchangeDialog.md`
- `source-3/project-documentation/by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`

Validator-owned/generated side effects were produced by validator commands, not manual edits:

- `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-research-tracker.md`
- `project-level/-auto-completion-stats.md`
- validator registry/hash state and autogen backup outputs reported by command `000000001256`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00049P-ExchangeDialogConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/00049P-ExchangeDialogConstructor-source-quality.md","timestamp":"2026-06-29T21:49:29","uid":"00049P"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00049P-ExchangeDialogConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00049P-ExchangeDialogConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00049P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
