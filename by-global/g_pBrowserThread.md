*** UID:0000QE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Source declaration for g_pBrowserThread is emitted by [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pBrowserThread

## Status

- Confidence: strong for singleton role, exact lifetime evidence, and browser source ownership; medium-high for exact original declaration/linkage shape.
- Active IDA MCP label: `unk_67AB88` in B010 accepted session `80de0a67`.
- Source-facing reconstruction name: `g_pBrowserThread`.
- IDA storage candidate: `0x0067ab88`; older docs may call it `dword_67AB88`, but the active B010 MCP session renders it as `unk_67AB88`.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md)
- Likely type: `BrowserThread*`
- Rebuild handling: source-declared module/global singleton pointer; the exact storage address is linker-generated data for the source declaration.
- Owner/emitter route: [UID:0000HV][Browser](by-file/Browser.md). First-draft declaration readiness is accepted through the paired storage page [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md), which emits `static BrowserThread *g_pBrowserThread;` together with `g_pCurrentBrowserHost`. This symbol page remains the per-global evidence record and should not duplicate the paired declaration unless the emitter strategy changes.
- Formal output for this symbol page is therefore a source-coverage comment to [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md), not a duplicate declaration.

## Observed Evidence

`BrowserControlPaneOld::BrowserControlPaneOld` allocates a `BrowserThread`, installs the browser-thread vtable, stores the embedded `Browser` object pointer and bounds, writes the active `unk_67AB88` / source-facing `g_pBrowserThread` slot, and starts the thread through the shared worker launch helper.

`BrowserThread` teardown clears the same singleton. IDA xrefs to `0x0067ab88` include:

- `0x004700ef` / `0x004700f6` inside [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md).
- `0x0046eff6` inside [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md).
- `0x004706fc` inside [UID:00032V][0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor](by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md).
- BrowserDialogOld and old-browser event paths at `0x004694c0`, `0x0046955c`, `0x00469582`, `0x004695c0`, `0x00469620`, `0x0046f870`, and `0x0046f8cb`.

2026-06-27 B010 accepted live MCP session `80de0a67` confirms exactly eleven data refs to `0x0067ab88`:

| Address | Function/context | Meaning |
| --- | --- | --- |
| `0x004694c0` | raw BrowserDialogOld helper | Posts `PostThreadMessageA([g_pBrowserThread + 0x60], 0x500, 0, 0)`. |
| `0x0046955c` / `0x00469582` | BrowserDialogOld key path | Posts close message `0x500` for Escape-style handling. |
| `0x004695c0` | BrowserDialogOld mouse/bounds path | Reads state from the current BrowserThread object, including bounds at `+0x70`. |
| `0x00469620` | BrowserDialogOld action/redraw callback | Posts private message `0x501`. |
| `0x0046eff6` | BrowserThread non-deleting destructor | Clears the singleton before chaining to `Thread::~Thread`. |
| `0x0046f870` / `0x0046f8cb` | Browser `Invoke`/dispatch path | Posts private close message through `[g_pBrowserThread + 0x60]`. |
| `0x004700ef` / `0x004700f6` | BrowserControlPaneOld constructor | Stores the allocated BrowserThread pointer or clears the slot on the allocation/edge path. |
| `0x004706fc` | BrowserThread scalar deleting destructor | Repeats the singleton clear for the deleting-destructor path. |

The same MCP pass found no active saved data label for this address; current active output uses `unk_67AB88`. That label is evidence of current IDB state only, not the source-facing name.

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

Do not reowner this symbol to the BrowserThread class solely because the stored object is a `BrowserThread`. The declaration is Browser module state, and consumers include BrowserDialogOld helpers and Browser event-sink paths outside the class. The paired by-memory storage item [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) remains owned/emitted by [UID:0000HV][Browser](by-file/Browser.md).

## Type Hypothesis

Likely declaration:

```cpp
static BrowserThread *g_pBrowserThread;
```

This declaration is now first-draft ready through [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md). Keep `static` as the current Browser module spelling until source split/linkage is reviewed. If the final source keeps old dialog/control code in separate browser files, this may need a browser-private header declaration rather than true file-local storage.

Active IDB RTTI includes `Singleton<BrowserThread>` names near BrowserThread type metadata. Current docs do not prove that `0x0067ab88` must be emitted as a template static-member declaration, so this remains a spelling caveat rather than a blocker to the accepted source-facing `BrowserThread *g_pBrowserThread` declaration.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md)
- [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)
- [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md)
- [UID:0000OR][Thread](by-file/Thread.md)

## Changes

- 2026-06-29 B002 Browser empty-emitter first-batch implementation:
  - Score unchanged at `86/88`.
  - Summary/evidence: inserted formal coverage comment `// Source declaration for g_pBrowserThread is emitted by [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md).` This resolves the empty emitter without duplicating the paired storage declaration `static BrowserThread *g_pBrowserThread;` already emitted by [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md).
- 2026-06-27 B010 accepted implementation callback:
  - Summary/evidence: updated active IDA label state to `unk_67AB88` from MCP session `80de0a67`, recorded the exact 11-xref inventory, and marked the source-facing declaration `static BrowserThread *g_pBrowserThread;` first-draft ready through the paired storage emitter [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md).
  - Source-quality disposition: keep Browser file ownership/emission through [UID:0000HV][Browser](by-file/Browser.md); reject raw `DWORD`/`void *`, Thread-file ownership, direct BrowserThread class ownership for the storage declaration, and a mandatory `Singleton<BrowserThread>` static-member spelling absent stronger source/linkage evidence.
- 2026-06-06 A010 legacy thread singleton evidence consolidation:
  - Before: `COMPLETION:82`, `CONFIDENCE:78`, with constructor/destructor xrefs and type hypothesis but limited destructor-companion and ownership separation detail.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, source-declared storage handling, autogen/source-gate note, lifetime evidence table, ordinary/scalar destructor parity, and clearer browser-vs-thread-infrastructure ownership rationale.
  - Summary/evidence: [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md) confirms the exact three-instruction ordinary destructor with singleton clear at `0x0046eff6`, scalar deleting companion clear at `0x004706fc`, BrowserThread vtable refs, and thread-base tail call; [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md) ties construction, COM host setup, and old-browser message paths to the browser source module.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/78`. Summary/evidence: the page documents the legacy browser-thread singleton role, constructor/destructor xrefs, old-browser event paths, ownership/type hypothesis, and refs; exact final linkage/source spelling remained provisional at that time, while the accepted source-facing type is now `BrowserThread *`.
- 2026-06-05: Marked reconstructable under [UID:0000HV][Browser](by-file/Browser.md). Evidence: live IDA MCP reports xrefs to `0x0067ab88` from old-browser control construction, browser thread teardown, and old-browser event paths; decompilation confirms `0x0046ff50` writes `dword_67AB88` after allocating the `BrowserThread`, and `0x0046eff0` clears it during non-deleting teardown.
