*** UID:0000RQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMiscWorkThread

## Status

- Confidence: strong for storage and owner.
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

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0067ab50` is `dword_67AB50`, size `4`, in `.data`, with 8 data xrefs.
- Live IDA xrefs confirm the documented lifecycle writes: `0x005281f1` and `0x005281f8` in `sub_5281B0`, `0x00528262` in `sub_528230`, `0x005283e0` in `sub_5283E0`, and `0x00528429` in `sub_5283F0`.
- Live IDA xrefs also confirm the documented consumers at `0x00464a88` in `sub_464A60`, `0x00530141` in `sub_530060`, and `0x00549295` in `sub_549220`.
- [UID:0001CK][0x00528290-0x005283d4.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d4.CashShopRequestAuthDirectory.md) documents why the request wrappers are stale `CashShopRequest` ownership and should remain under `MiscWorkThread`.
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
- Changed to: completion `76`, confidence `82`.
- Summary/evidence: the page now consolidates exact storage, owner, constructor/destructor writes, consumer reads, and stale `CashShopRequest` correction evidence verified against live IDA MCP xrefs on 2026-05-30. Confidence remains below fully settled because final original source path/wrapper names are still provisional.
