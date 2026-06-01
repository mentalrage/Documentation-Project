*** UID:0000QE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBrowserThread

## Status

- Confidence: strong for singleton role, medium for exact final type.
- Current Wave3 kind: `global-data`
- Current generated owner files: `class_BrowserThread.cpp` and `class_BrowserControlPaneOld.cpp`
- IDA storage candidate: `0x0067ab88` (`dword_67AB88`)
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md)

## Observed Evidence

`BrowserControlPaneOld::BrowserControlPaneOld` allocates a `BrowserThread`, installs the browser-thread vtable, stores the embedded `Browser` object pointer and bounds, writes `dword_67AB88`, and starts the thread through the shared worker launch helper.

`BrowserThread::ScalarDeletingDestructor` clears the same singleton in generated source. IDA xrefs to `0x0067ab88` include:

- `0x004700ef` / `0x004700f6` inside `BrowserControlPaneOld::BrowserControlPaneOld`
- `0x0046eff6` inside [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md)
- `0x004706fc` inside `BrowserThread::ScalarDeletingDestructor`
- browser dialog and old-browser event paths around `0x004694c0`, `0x0046955c`, and `0x0046f870`

## Ownership Hypothesis

This is the active legacy browser thread singleton. It should migrate with `browser/Browser.cpp` or a split `browser/BrowserThread.cpp`.

## Type Hypothesis

Likely declaration:

```cpp
static BrowserThread* g_pBrowserThread;
```

Keep `static` provisional until storage/linkage is reviewed.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md)
- [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents the legacy browser-thread singleton role, constructor/destructor xrefs, old-browser event paths, ownership/type hypothesis, and refs; exact final linkage/type remains provisional.
