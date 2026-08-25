*** UID:0000QJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CheatDetector;

CheatDetector *g_pCheatDetector = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pCheatDetector

## Status

- Confidence: strong for address and singleton role.
- Address: [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md)
- Current IDA name: `g_pCheatDetector`
- Likely owner file: [UID:0000I6][CheatDetector](by-file/CheatDetector.md)

## Purpose

`g_pCheatDetector` stores the active process-wide [UID:000020][CheatDetector](by-class/CheatDetector.md) singleton. Startup allocates the object during `Application::Initialize`, the constructor stores the pointer, and destructor/clear helpers reset it.

## Evidence Notes

- IDA MCP decompilation of `0x00483f00` writes `dword_67AB3C = this`.
- IDA MCP decompilation of `0x00483ff0` and `0x00484000` clears `dword_67AB3C`.
- 2026-05-24 IDA recheck found five data refs: startup cleanup at `0x00464ba0`, constructor writes at `0x00483f33` and `0x00483f3a`, clear helper `0x00483ff0`, and scalar deleting destructor `0x0048400f`.
- 2026-05-26 exact memory page: [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md). The same pass kept `0x00483ff0` as a real clear helper omitted by active output.
- The working symbol name for the same storage is `g_pCheatDetector`.
- 2026-06-16 C001 live IDA refresh on session `b001_mappane_0001AW_20260616` reconfirmed zeroed current storage bytes, the same five direct data xrefs, `CheatDetectorConstructor` publishing/clearing the singleton, `ClearCheatDetectorSingleton`, and `CheatDetectorScalarDeletingDestructor`. C001 then saved IDA names for the singleton storage and the three lifecycle functions.
- 2026-06-19 B012 source-quality reanalysis separates the singleton clear paths: constructor `0x00483f00` publishes/guard-clears `g_pCheatDetector`; `0x00483ff0` is the no-argument constructor-unwind `ClearCheatDetectorSingleton` helper reached from cleanup metadata at `0x005fc446`; `0x00484000` is `CheatDetectorScalarDeletingDestructor`, which clears the singleton after confirmed `TimerHandler_dtor` base teardown and before optional free. Application cleanup at `0x00464ba0` is a consumer/read-dispatch path, not the owner of this global or the source home for the clear helper.
- First-draft source declaration is ready as `CheatDetector *g_pCheatDetector = 0;` in [UID:0000I6][CheatDetector](by-file/CheatDetector.md). The exact timer-helper route and final member names still cap final-source confidence, but no longer block a draft singleton definition.
- Application cleanup at `0x00464ba0` is a consumer that checks and dispatches deletion through the vtable; the owner remains `CheatDetector.cpp`, where the constructor publishes the singleton and destructor support clears it.

## Cross-References

- [UID:0000I6][CheatDetector](by-file/CheatDetector.md)
- [UID:000020][CheatDetector](by-class/CheatDetector.md)
- [UID:000108][0x00483f00-0x0048402d.CheatDetector](by-memory/0x00483f00-0x0048402d.CheatDetector.md)
- [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)

## B004 One-Definition And Lifetime Closure

- This semantic global owns the sole externally linked zero definition at emitter position `0`; physical [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md) is false/non-emitting storage evidence.
- Exact backing range `[0x0067ab3c,0x0067ab40)` contains `00 00 00 00` in the IDB and both identical executable copies; physical-byte SHA256 is `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Five exact references close the lifetime: Application cleanup read `0x00464ba0`, constructor publish `0x00483f33`, constructor fallback clear `0x00483f3a`, unwind clear `0x00483ff0`, and scalar-wrapper clear `0x0048400f`.
- Direct `Singleton<CheatDetector>` RTTI and PMD `+4,-1,0` prove template-base lifetime lowering and EBO. The source definition remains an ordinary project global because cleanup and other module-facing documentation use the external `g_pCheatDetector` contract.
- The header-facing declaration is `extern CheatDetector *g_pCheatDetector;` on [UID:000020][CheatDetector](by-class/CheatDetector.md); this page emits only the forward declaration and definition.
- No alias storage, alternate writer, second definition, explicit constructor assignment, compiler clear helper, or manually lowered template-static form is supported.
- Historical `0xffffffff` evidence is superseded by current zero bytes and is not a valid initializer.

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/86`. Summary/evidence: the page documents address/memory page, singleton purpose, startup allocation, constructor/destructor/clear evidence, IDA recheck refs, working symbol name, and anticheat refs.
- 2026-06-05: Marked reconstructable under [UID:0000I6][CheatDetector](by-file/CheatDetector.md). Evidence: live IDA MCP reports five xrefs to `0x0067ab3c`; decompilation confirms `0x00483f00` writes `dword_67AB3C`, `0x00483ff0` clears it, and `0x00484000` clears it in the deleting destructor path.
- 2026-06-16 C001 Goal 2 global/IDA refresh: raised `86/86` to `88/89` after live IDA reconfirmed storage bytes, xrefs, constructor/clear/destructor behavior, owner route through [UID:0000I6][CheatDetector](by-file/CheatDetector.md), and saved `g_pCheatDetector` plus lifecycle function names in the IDB. No final C++ was added because base/member naming and the raw time-snapshot helper remain below final-source confidence.
- 2026-06-19 B012 source-quality incorporation: no score change; incorporated the distinction between constructor-unwind `ClearCheatDetectorSingleton`, scalar deleting-destructor singleton clear, and application cleanup consumer semantics, plus the confirmed `TimerHandler_dtor` base teardown.
- 2026-06-20 B002 Rule 26 incorporation: no score change; added first-draft source definition `CheatDetector *g_pCheatDetector = 0;` and clarified that `Application` cleanup is a consumer while `CheatDetector.cpp` owns the global's declaration/lifetime.
