*** UID:0000QE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBrowserThread

## Status

- Confidence: strong for singleton role, exact lifetime evidence, and browser source ownership; medium-high for final declaration/linkage shape.
- IDA storage candidate: `0x0067ab88` (`dword_67AB88`)
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md)
- Likely type: `BrowserThread*`
- Rebuild handling: source-declared module/global singleton pointer; the exact storage address is linker-generated data for the source declaration.
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md); C++ remains blank because the ordinary/scalar destructor representation and final declaration placement are below the `95+` source gate.

## Observed Evidence

`BrowserControlPaneOld::BrowserControlPaneOld` allocates a `BrowserThread`, installs the browser-thread vtable, stores the embedded `Browser` object pointer and bounds, writes `dword_67AB88`, and starts the thread through the shared worker launch helper.

`BrowserThread` teardown clears the same singleton. IDA xrefs to `0x0067ab88` include:

- `0x004700ef` / `0x004700f6` inside `BrowserControlPaneOld::BrowserControlPaneOld`
- `0x0046eff6` inside [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md)
- `0x004706fc` inside `BrowserThread::ScalarDeletingDestructor`
- browser dialog and old-browser event paths around `0x004694c0`, `0x0046955c`, and `0x0046f870`

## Lifetime Evidence

| Site | Use | Evidence owner |
| --- | --- | --- |
| `0x004700ef` / `0x004700f6` | `BrowserControlPaneOld` constructor stores the allocated `BrowserThread` singleton. | [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md), with focused constructor child evidence linked there. |
| `0x0046eff6` | Ordinary non-deleting destructor clears the singleton and tail-calls `Thread::~Thread`. | [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md). |
| `0x004706fc` | Scalar deleting destructor repeats the singleton clear before delete-flag handling. | Scalar deleting companion documented by the BrowserThread destructor page. |
| `0x004694c0`, `0x0046955c`, `0x00469620` family | Old BrowserDialog methods post private browser messages through the thread id at `g_pBrowserThread + 0x60`. | Confirms this storage is a legacy browser-thread bridge, not a generic thread manager slot. |

## Ownership Hypothesis

This is the active legacy browser thread singleton. It should migrate with `browser/Browser.cpp` or a split `browser/BrowserThread.cpp`.

Keep this global under the browser module, not [UID:0000OR][Thread](by-file/Thread.md). The base thread destructor is generic infrastructure, but the singleton storage, old dialog message bridge, browser-control construction, and COM host setup are browser-specific.

## Type Hypothesis

Likely declaration:

```cpp
static BrowserThread* g_pBrowserThread;
```

Keep `static` provisional until storage/linkage is reviewed. If the final source keeps old dialog/control code in separate browser files, this may need a browser-private header declaration rather than true file-local storage.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md)
- [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)
- [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md)
- [UID:0000OR][Thread](by-file/Thread.md)

## Changes

- 2026-06-06 A010 legacy thread singleton evidence consolidation:
  - Before: `COMPLETION:82`, `CONFIDENCE:78`, with constructor/destructor xrefs and type hypothesis but limited destructor-companion and ownership separation detail.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, source-declared storage handling, autogen/source-gate note, lifetime evidence table, ordinary/scalar destructor parity, and clearer browser-vs-thread-infrastructure ownership rationale.
  - Summary/evidence: [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md) confirms the exact three-instruction ordinary destructor with singleton clear at `0x0046eff6`, scalar deleting companion clear at `0x004706fc`, BrowserThread vtable refs, and thread-base tail call; [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md) ties construction, COM host setup, and old-browser message paths to the browser source module.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents the legacy browser-thread singleton role, constructor/destructor xrefs, old-browser event paths, ownership/type hypothesis, and refs; exact final linkage/type remains provisional.
- 2026-06-05: Marked reconstructable under [UID:0000HV][Browser](by-file/Browser.md). Evidence: live IDA MCP reports xrefs to `0x0067ab88` from old-browser control construction, browser thread teardown, and old-browser event paths; decompilation confirms `0x0046ff50` writes `dword_67AB88` after allocating the `BrowserThread`, and `0x0046eff0` clears it during non-deleting teardown.
