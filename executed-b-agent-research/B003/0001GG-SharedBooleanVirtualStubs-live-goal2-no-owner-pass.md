** TARGET-REPORT-UID:0001GG **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Final Recommendation

Keep [UID:0001GG] `0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs` unchanged:

- `CANONICAL_OWNER:NONE`
- `EMITTER_UIDS:` blank
- `RECONSTRUCTABLE:TRUE`
- no split at this time
- no new child pages
- no coverage-report row change required

This is reconstructable code, but it is not a source-output unit under the current rules. IDA proves the two physical functions are tiny constant-return virtual bodies reused by unrelated source families: the `Effects` / `ScreenEffecter` family, the `SystemMessagePanes` marker/color-message classes, and CRT/runtime table artifacts. The correct final reconstruction is per-owning-class trivial virtual methods, emitted through those class/file owners once the final virtual names and declarations are known. Emitting this physical folded address through `0000IZ`, `0000OE`, or both would create a synthetic shared helper that the evidence does not support as original source.

Coverage-report action: none. The current row already records the correct no-owner/non-emitting decision. If a supervisor still wants the exact row text carried forward, keep:

```text
    - [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) 0x0055c1b0-0x0055c1c3 | shared virtual stubs | SharedBooleanVirtualStubs : reconstructable : 86% : strong : A002 2026-06-14 repaired stale one-byte-short range/name, set canonical owner NONE and blank emitters because true/false stubs are folded across system-message and effecter vtables, reconfirmed 3-byte function sizes, 25/32 xref counts, named system-message vtables, effecter refs, constant-return decompilation, and exact predecessor/stub/padding bytes.
```

# Supporting Research

## Scope

Target reviewed:

- UID: `0001GG`
- Page: `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md`
- Current metadata: `86/89`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank C++.
- Tracker assignment: active 2026-06-14 live Goal 2 no-owner memory pass for Agent-B003.

Instructions reviewed for this pass:

- `tools/leaser/Agents/Agent-B003/goal.md`
- `tools/leaser/Agents/Supervisor.md`
- `by-structure.md`
- `inference_research.md`
- current `no_owner_b-agent-tracker.md`

Current documentation checked as evidence context, not as authority:

- [UID:0000IZ] `by-file/Effects.md`
- [UID:0000OE] `by-file/SystemMessagePanes.md`
- [UID:0001GE] `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`
- [UID:0001YO] `by-type/by-vtable/ScreenEffecterVtableFamily.md`
- [UID:0002OR] `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`
- [UID:00026M] `by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md`
- [UID:0003GD] `HeaderSystemMessageVtableData`
- [UID:0003GE] `FooterSystemMessageVtableData`
- [UID:0003GF] `ColorStringSystemMessageVtableData`
- [UID:000061] `HeaderSystemMessage`
- [UID:00005D] `FooterSystemMessage`
- [UID:000030] `ColorStringSystemMessage`
- [UID:0000C9] `ScreenEffecter`

## IDA MCP Evidence

Live IDA MCP session:

- database/session: `a001_goal2_class_batch`
- input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- active: true
- analyzing: false

Function boundary checks:

| Query | IDA result |
| --- | --- |
| `0x0055c1a0` | inside predecessor `sub_55C180`, size `0x24`; tail is `pop ebp; retn 4` |
| `0x0055c1a4` | not a function |
| `0x0055c1b0` | `sub_55C1B0`, size `0x3` |
| `0x0055c1b3` | not a function |
| `0x0055c1c0` | `sub_55C1C0`, size `0x3` |
| `0x0055c1c3` | not a function |
| `0x0055c1d0` | `sub_55C1D0`, size `0x2f` |

Behavior checks:

- `decompile(0x0055c1b0)` returns `char sub_55C1B0() { return 1; }`.
- `decompile(0x0055c1c0)` returns `char sub_55C1C0() { return 0; }`.
- `callees` for both `0x0055c1b0` and `0x0055c1c0` returns empty lists.
- `disasm(0x0055c1b0)` is `mov al, 1; retn`.
- `disasm(0x0055c1c0)` is `xor al, al; retn`.

Raw bytes from `0x0055c1a0`:

```text
5d c2 04 00
cc cc cc cc cc cc cc cc cc cc cc cc
b0 01 c3
cc cc cc cc cc cc cc cc cc cc cc cc cc
32 c0 c3
cc cc cc cc cc cc cc cc cc cc cc cc cc
56 8b f1 ...
```

Interpretation:

- predecessor returns at `0x0055c1a0-0x0055c1a4`
- alignment at `0x0055c1a4-0x0055c1b0`
- true stub at `0x0055c1b0-0x0055c1b3`
- alignment at `0x0055c1b3-0x0055c1c0`
- false stub at `0x0055c1c0-0x0055c1c3`
- alignment at `0x0055c1c3-0x0055c1d0`
- next function starts at `0x0055c1d0`

Signature and pattern checks:

- Exact range signature `B0 01 C3 CC CC CC CC CC CC CC CC CC CC CC CC CC 32 C0 C3` is unique.
- Individual patterns `B0 01 C3` and `32 C0 C3` have many hits in the executable, so the individual instruction bodies are common trivial returns; ownership must come from function heads and xrefs, not opcode uniqueness.

## Xref Evidence

IDA `xrefs_to(0x0055c1b0)` returns 25 xrefs:

- 1 code xref from `?pre_c_initialization@@YAHXZ` at `0x005c8489`.
- 20 effecter-family `.rdata` refs from `0x006235c4` through `0x00623cf8`.
- 2 system-message refs at `0x0062d6b8` and `0x0062d6e0`.
- 2 later runtime/CRT data refs at `0x00637548` and `0x0063754c`.

IDA `xrefs_to(0x0055c1c0)` returns 32 xrefs:

- 28 effecter-family `.rdata` refs from `0x006235a4` through `0x00623d00`.
- 4 system-message refs at `0x0062d6bc`, `0x0062d6dc`, `0x0062d700`, and `0x0062d704`.

Named effecter table evidence from `entity_query(0x006235a0-0x00623d20)` includes:

- `0x006235a4` `??_7ScreenEffecter@@6B@`
- `0x006235c4` `??_7PixelEffecter@@6B@`
- `0x006235e8` `??_7OverlayEffecter@@6B@`
- `0x00623694` `??_7OverlayImageEffecter@@6B@`
- `0x00623740` `??_7OverlayFrameImageEffecter@@6B@`
- `0x006237ec` `??_7OverlayImageOnPointEffecter@@6B@`
- `0x00623898` `??_7OverlayMovingImageEffecter@@6B@`
- `0x00623944` `??_7FilterEffecter@@6B@`
- `0x006239ec` `??_7SolidColorFilterEffecter@@6B@`
- `0x00623a94` `??_7CloudFilterEffecter@@6B@`
- `0x00623b3c` `??_7StaticCloudFilterEffecter@@6B@`
- `0x00623be4` `??_7EarthquakeEffecter@@6B@`
- `0x00623c08` `??_7XWaveEffecter@@6B@`
- `0x00623c2c` `??_7YFlipEffecter@@6B@`
- `0x00623c50` `??_7WaterFilterEffecter@@6B@`
- `0x00623cf8` `??_7LakeEffecter@@6B@`

Representative effecter dwords:

- `0x006235a4`, `0x006235a8`, `0x006235ac` all point to `0x0055c1c0`.
- `0x006235c4` points to `0x0055c1b0`.
- `0x006235c8` and `0x006235cc` point to `0x0055c1c0`.

Named system-message table evidence from `entity_query(0x0062d690-0x0062d720)` includes:

- `0x0062d6a0` `??_7SystemMessagePane@@6B@_1`
- `0x0062d6ac` `??_7HeaderSystemMessage@@6B@`
- `0x0062d6d0` `??_7FooterSystemMessage@@6B@`
- `0x0062d6f4` `??_7ColorStringSystemMessage@@6B@`
- `0x0062d718` `??_7ForcedInformMessageDialog@@6B@`

Representative system-message dwords:

- `0x0062d6b8` points to `0x0055c1b0`.
- `0x0062d6bc` points to `0x0055c1c0`.
- `0x0062d6dc` points to `0x0055c1c0`.
- `0x0062d6e0` points to `0x0055c1b0`.
- `0x0062d700` and `0x0062d704` point to `0x0055c1c0`.

Runtime/CRT table evidence:

- IDA marks `0x00637548` and `0x0063754c` as data xrefs to `0x0055c1b0`.
- Raw dword reads around `0x00637520` show additional untyped `0x0055c1b0` values at `0x0063757c`, `0x0063758c`, `0x00637598`, and `0x006375a4`.
- Nearby global names are CRT/math strings such as `aTanh`, `aAsin`, `aAcos`, `aAtan`, `aAtan2`, and `aSqrt`.
- `xrefs_to(0x00637548)` and `xrefs_to(0x0063754c)` return no incoming xrefs to the table entries themselves.

This runtime region does not provide a NexusTK game source owner. It only reinforces that the true stub address is reused beyond one game class family.

## Owner Candidate Ranking

| Candidate | Evidence for | Decision |
| --- | --- | --- |
| [UID:0000IZ] `Effects` / `ScreenEffecter` family | Most xrefs are effecter vtable slots. `ScreenEffecterVtableFamily` and `ScreenEffecterVtableData` are owned under `Effects`. | Rejected as sole canonical owner. It cannot explain the system-message vtable slots or CRT/runtime refs. |
| [UID:0000OE] `SystemMessagePanes` and classes [UID:000061], [UID:00005D], [UID:000030] | Header/Footer/ColorString vtable children point directly at both stubs and are class-owned under `SystemMessagePanes`. | Rejected as sole canonical owner. It cannot explain the larger effecter-family xref set or CRT/runtime refs. |
| CRT/runtime library area | `?pre_c_initialization@@YAHXZ` code ref and `0x006375xx` table values point at the true stub. Nearby names are CRT/math strings. | Rejected as source owner. These refs are runtime artifacts, not the semantic virtual-method owner. |
| Split into true-stub and false-stub children | The two bodies are separate IDA functions and have different xref sets. | Not needed now. Both children would inherit the same folded, cross-family ownership problem and remain no-owner/non-emitting. A split would not improve routing or reconstruction. |
| Multi-emitter `0000IZ,0000OE` | Both source families need equivalent boolean virtual semantics in final source. | Rejected. It would emit one physical folded helper into two source routes, which is not the source-level construct. Emit class methods later through the owning class/file pages instead. |
| `CANONICAL_OWNER:NONE`, blank emitters | The exact physical addresses are shared/folded code bodies used across unrelated owners and runtime artifacts. | Accepted. This is the only decision consistent with the current owner/emitter separation. |

## Why No-Owner And Non-Emitting Is Correct

The code is reconstructable because the semantics are known: one virtual body returns `true`, one returns `false`, and vtable slots require those boolean results in the reconstructed source model.

The exact by-memory page should still remain non-emitting because it is a physical binary pooling point, not a source-level unit. The source-side reconstruction should look like ordinary class virtual overrides or inherited defaults in the relevant classes. The compiler/linker can then fold identical trivial bodies into the same addresses. A generated standalone helper for `0x0055c1b0` or `0x0055c1c0` would be an artifact of the binary layout, not evidence-backed original C++.

This also explains why blank `EMITTER_UIDS` is correct even though `RECONSTRUCTABLE:TRUE` is correct. The current system's code-entry gate requires an output route and final-source quality C++; this page has neither. Its role is to document the folded physical functions and route future source reconstruction work back to the class/file owners that use the vtable slots.

## Split Assessment

No child files should be created in this pass.

Reasons:

- The target range is already exact for the paired micro-stub island: true body, padding, false body, and stop before `sub_55C1D0`.
- The exact range signature is unique.
- The two individual bodies are modeled as separate IDA functions, but each function has cross-family xrefs and no single source owner.
- Splitting into `ReturnTrueVirtualStub` and `ReturnFalseVirtualStub` would produce two more no-owner/non-emitting pages and would not improve the coverage-report row, canonical owner, emitter route, or final reconstruction.
- The useful future split is semantic, not physical: once final virtual names are proven, per-class methods can be documented/emitted under `Effects` classes and `SystemMessagePanes` classes.

## Reclassification Assessment

Do not reclassify this as non-reconstructable.

The physical sharing/folding is compiler/linker behavior, but the return values are source-observable virtual-method behavior. `RECONSTRUCTABLE:TRUE` is still correct because the reconstructed project must express equivalent virtual semantics. The blank C++ block remains correct because the page is below final-source quality and has no valid single emitter route.

## Coverage Report

No edit is needed to `by-memory/-coverage-report.md`.

The current row already states:

- reconstructable
- `86%`
- strong confidence
- canonical owner `NONE`
- blank emitters
- folded across system-message and effecter vtables
- 3-byte function sizes
- 25/32 xref counts
- constant-return behavior
- corrected boundaries and padding

## Pass Notes

- No `by-*` files were edited.
- No lease was required because only this Agent-B003 research report was created.
- No dry runs were used.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001GG-SharedBooleanVirtualStubs-live-goal2-no-owner-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001GG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
