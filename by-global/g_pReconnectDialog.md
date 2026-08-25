*** UID:0004SP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ReconnectDialog;

ReconnectDialog *g_pReconnectDialog = NULL;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pReconnectDialog

## Status

- Symbol kind: process-wide singleton pointer.
- Source-facing type: `ReconnectDialog *`.
- Exact storage: [UID:0004SR][0x0067ab58-0x0067ab5c.g_pReconnectDialog](by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md).
- Source owner and emitter: [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), reconstructed as `NexusTK/network/ReconnectDialog.cpp`.
- Rebuild handling: source-authored external definition with source-declared/generated-binary four-byte storage.
- Confidence: very strong for type, zero initialization, external linkage, direct Singleton lifetime, storage, source file, and one-definition routing; the exact `g_p...` spelling and `NULL` token remain source-facing lexical inferences.

## Source Definition And One-Definition Policy

This page emits the sole source definition:

```cpp
class ReconnectDialog;

ReconnectDialog *g_pReconnectDialog = NULL;
```

The forward declaration is sufficient for the pointer definition. Exact child [UID:0004SR][0x0067ab58-0x0067ab5c.g_pReconnectDialog](by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md) represents the linker-assigned storage and emits only a covered-storage comment through `[[CHILDREN]]`; it must not emit a second definition, raw address object, anonymous array, or explicit `Singleton<ReconnectDialog>` specialization.

`NULL` preserves the loader-zero-filled image value and matches the accepted era-consistent project style. The exact original token could have been `0` or an omitted initializer, but no observed behavior permits the stale `0xffffffff` value or a `reinterpret_cast` sentinel.

## Exact Storage And Lifetime Evidence

- The exact dword at `0x0067ab58` reads `00 00 00 00` in the healthy evidence-time IDB.
- The slot is in the virtual-only tail of `.data`, beyond the section's raw-backed bytes, so the loader supplies zero-filled static storage.
- The PE has no base relocation directory and no target relocation.
- Exact class identity is proved by `.?AVReconnectDialog@@` RTTI, `0x274`-byte allocations, and the direct `Singleton<ReconnectDialog>` base descriptor at PMD `+0x270`, `pdisp=-1`, `vdisp=0`.
- Empty-base optimization overlaps the Singleton base at `+0x270` with the derived reconnect-state byte while retaining a `0x274` complete allocation. Constructor publication and destruction clears are compiler lowering of that direct base lifetime, not handwritten assignments or cleanup calls.

## Ten-Reference Classification

| Address | Access | Meaning |
| --- | --- | --- |
| `0x00466f22` | read | The Application heartbeat helper requires this pointer and `g_pConnectionClosedDialog` to be null before sending. |
| `0x00553da7` | read | Reconnect-click handling checks and deletes an existing reconnect dialog before replacement. |
| `0x00553e08` | write | Replacement construction publishes the complete `ReconnectDialog` after Singleton-base adjustment. |
| `0x00553e0f` | clear | Compiler adjusted-null fallback for replacement construction. |
| `0x00553fa4` | write | Default constructor publishes the complete reconnect dialog. |
| `0x00553fab` | clear | Compiler adjusted-null fallback for that constructor. |
| `0x00554051` | write | Parent-taking constructor publishes the complete reconnect dialog. |
| `0x00554058` | clear | Compiler adjusted-null fallback for that constructor. |
| `0x00554560` | clear | EH-only `Singleton<ReconnectDialog>` base-destructor instantiation. |
| `0x005545f6` | clear | Scalar deleting wrapper inlines the same Singleton-base destruction effect. |

## Source Placement And Linkage

- `NexusTK/network/ReconnectDialog.cpp` is the strongest source route because all replacement, constructor, reconnect, timeout, and teardown writers belong to the ConnectionClosedDialog/ReconnectDialog family.
- Application heartbeat code is a cross-module read-only consumer. That consumer proves external linkage under the accepted source split but does not own the declaration.
- `login/ReconnectDialog.cpp` remains a weaker historical folder alternative. Packet/session recovery behavior and the current project route favor `network/`.
- Direct class-static-member syntax and explicit template specialization are rejected because no source/PDB symbol proves those lexical forms. The ordinary external pointer definition is the strongest project-wide source model for the binary-proven per-specialization static storage.

## Source And Compiler Boundary

Human source should contain the pointer definition and the direct `Singleton<ReconnectDialog>` class inheritance. It should not contain:

- explicit constructor publication or destructor clear assignments;
- EH cleanup helper calls;
- vptr stores, RTTI objects, adjustor thunks, scalar flags, delete wrappers, or exception tables;
- raw addresses or decompiler aliases such as `dword_67AB58`;
- a centralized Singleton registry or duplicate storage object.

## Score Rationale

- Completion `91`: exact type, zero storage, all ten refs, direct Singleton source cause, external linkage, source placement, one-definition policy, and generated-output route are documented.
- Confidence `93`: bytes, PE mapping, RTTI, PMD/EBO, constructor/EH/scalar evidence, and cross-module consumption independently agree. Original lexical spelling, header location, and initializer token cap the score below final-audit levels.

## Cross-References

- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- [UID:0000BR][ReconnectDialog](by-class/ReconnectDialog.md)
- [UID:00038L][0x00553f40-0x005544b8.ReconnectDialogMethods](by-memory/0x00553f40-0x005544b8.ReconnectDialogMethods.md)
- [UID:00038K][0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks](by-memory/0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md)
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md)
- [UID:0002VT][0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals](by-memory/0x0067ab54-0x0067ab5c.ConnectionReconnectDialogSingletonGlobals.md)
- [UID:0004SR][0x0067ab58-0x0067ab5c.g_pReconnectDialog](by-memory/0x0067ab58-0x0067ab5c.g_pReconnectDialog.md)
