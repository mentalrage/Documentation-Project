*** UID:0000RQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMiscWorkThread

## Status

- Confidence: strong for storage, owner, lifecycle writes, and feature consumers.
- Address: `0x0067ab50`
- Memory doc: [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md)
- Likely source module: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- Type hypothesis: `MiscWorkThread*`
- Evidence basis: IDA MCP xrefs and linked by-memory documentation.

## Role

`g_pMiscWorkThread` stores the singleton [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) instance. Application startup constructs the object, feature modules use the global to queue background work, and cleanup/destructor paths clear the pointer.

## Known Accesses

| Address | Access | Notes |
| --- | --- | --- |
| `0x00464715` | constructor call path | `Application::Initialize` constructs the `MiscWorkThread` object. |
| `0x00464a88` | cleanup path | `Application::CleanupResources` destroys the singleton if present. |
| `0x005281f1` / `0x005281f8` | write | `MiscWorkThread::MiscWorkThread` stores `this`. |
| `0x00528262` | clear | `MiscWorkThread::~MiscWorkThread` clears the global. |
| `0x005283e0` | clear helper | Small singleton-clear helper. |
| `0x00528429` | clear | Scalar deleting destructor clears the global. |
| `0x00530141` | read/use | Registration/NCA request path queues work through the singleton. |
| `0x00549295` | read/use | PatchPane2/download path queues HTTP work through the singleton. |

## Ownership Notes

- This global belongs with [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md), not [UID:00001H][CashShopRequest](by-class/CashShopRequest.md).
- Request wrappers at `0x00528290`, `0x00528310`, and raw `0x005283b0` should be documented as `MiscWorkThread` submission helpers because callers first read this singleton.

## Live Evidence

- IDA MCP on 2026-06-06 confirms `0x0067ab50` is a four-byte `.data` slot initialized to `0xffffffff`, with 8 direct data xrefs.
- Live IDA xrefs confirm the documented lifecycle writes: `0x005281f1` and `0x005281f8` in the constructor, `0x00528262` in the non-deleting destructor, `0x005283e0` in the singleton-clear helper, and `0x00528429` in the scalar deleting destructor.
- Live IDA xrefs also confirm the documented consumers at `0x00464a88` in Application cleanup, `0x00530141` in the registration/NCA request path, and `0x00549295` in the patch/download path.
- Live IDA decompilation confirms `0x005281b0` publishes the current object or zero fallback into the singleton slot and installs the `MiscWorkThread` vtable; `0x00528230`, `0x005283e0`, and `0x005283f0` clear the singleton during cleanup/destruction.
- [UID:0001CK][0x00528290-0x005283d5.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md) documents why the request wrappers are stale `CashShopRequest` ownership and should remain under `MiscWorkThread`.
- [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md) remains the canonical memory page for this slot and matches the live IDA check.

## Cross-References

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000MH][PatchPane](by-file/PatchPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `88`.
- Summary/evidence: the page now consolidates exact storage, owner, constructor/destructor writes, consumer reads, and stale `CashShopRequest` correction evidence verified against live IDA MCP xrefs. Confidence remains below fully settled because final wrapper names are still provisional.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LG`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067ab50` and decompilation of `0x005281b0`, `0x00528230`, `0x005283e0`, and `0x005283f0` prove NexusTK-owned `MiscWorkThread` singleton storage owned by [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-06 source-facing cleanup:
  - What existed before: score `76/82`, thin source-facing summary, and raw IDA labels in the evidence.
  - Changed to: score `84/88`, refreshed live xref/byte evidence, source-facing singleton wording, and synced the manual by-global coverage row.
  - Summary/evidence: current IDA MCP confirms initialized storage, constructor publish/fallback clear, destructor/helper/deleting-destructor clears, Application cleanup read, registration/NCA and patch/download consumers, and file-parent ownership through [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md). C++ remains blank under the final-code gate.
