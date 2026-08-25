** TARGET-REPORT-UID:0002JF **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002JF MenuItem Scalar Deleting Destructor Source-Quality Recheck

## Finalized Report / Current Recommendation

- Assignment id: `B003-goal2-menuitem-scalar-deleting-destructor-policy-0002JF-20260618`.
- Target: [UID:0002JF] `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md`.
- Current target state: `82/90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00007V`, `EMITTER_UIDS:00007V`, formal C++ blank.
- Recommendation: raise target to `86/92`, keep `RECONSTRUCTABLE:TRUE`, keep owner/emitter [UID:00007V] `MenuItem`, and keep the target `RECONSTRUCTION_CPP` block blank with an explicit no-formal-C++ proof.
- Source-level action: document an ordinary/default `MenuItem` destructor on [UID:00007V] `MenuItem` or the surrounding class support, not this exact wrapper body. This wrapper is compiler-generated MSVC deleting-destructor output from ordinary class destructor semantics.
- Rejected disposition: do not reclassify [UID:0002JF] as non-reconstructable/ignored. The exact wrapper body is compiler-generated, but the rebuilt source must still declare/define class destructor semantics that make this vtable slot and wrapper appear. Keeping the page reconstructable with no formal target C++ best matches the current source-declared/generated-binary policy.

The prior B003 PopupMenuControls pass did not clear `85/85` because it treated "target C++ remains blank for compiler-wrapper policy" as a score cap and only recommended keeping `82/90` or at most `84/90`. Under the current Rule 20 code-entry policy, blank target C++ is acceptable when the page records a target-specific no-code proof. This recheck adds that proof, including fresh raw PE bytes, exact flag behavior, pointer-route evidence, and class-level source replacement guidance.

## Target Inventory

| UID | Range | Current owner/emitter | Recommended owner/emitter | Score recommendation | C++ recommendation |
| --- | --- | --- | --- | --- | --- |
| `0002JF` | `0x005172e0-0x0051731e` | `00007V` / `00007V` | keep `00007V` / `00007V` | `82/90 -> 86/92` | keep formal target block blank; add ordinary/default `MenuItem` destructor guidance to support docs. |

Target classification:

- Binary entity kind: MSVC scalar deleting destructor wrapper.
- Source role: generated deleting-wrapper body for ordinary/default `MenuItem` destructor semantics.
- Vtable route: referenced from `MenuItem` primary vtable slot `+0x00` at `0x0061eb98` and `SeparatorMenuItem` vtable slot `+0x00` at `0x0061ebd0`.
- Direct caller route: none found in existing IDA-backed docs and none found by fresh `.text` rel32 scan. Runtime reachability is through vtable dispatch / delete expressions.

## Evidence Checked

Files and docs read or rechecked:

- `tools/leaser/Agents/Supervisor.md`, `tools/leaser/Agents/Agent-B003/goal.md`, and `tools/leaser/Agents/Agent-B003/notes.md`.
- `by-structure.md` and `inference_research.md`, especially current code-entry policy, compiler/linker-generated classification, and Rule 26 source-quality requirements.
- Primary target [UID:0002JF] `MenuItemScalarDeletingDestructor`.
- Support pages [UID:00007V] `MenuItem`, [UID:0000MN] `PopupMenuControls`, [UID:0001Y4] `MenuItemVtables`, [UID:0001V5] `MenuItemLayouts`, [UID:0002J3] `MenuItemConstructor`, [UID:0002JB] `SeparatorMenuItemConstructor`, [UID:0002JG] `StringMenuItemScalarDeletingDestructor`, [UID:0002J5] `MenuItemStateFlag1Accessor`, [UID:0002JH] `MenuItemSetStateFlag0`, [UID:0002JI] `MenuItemSetStateFlag1`, [UID:0000E8] `StringMenuItem`, [UID:0000CY] `SeparatorMenuItem`, and [UID:0001BK] `MenuPaneAndItems`.
- Helper/support pages [UID:000195] `LObjectRuntimeShell`, [UID:000370] `LObjectDestructorBody`, [UID:000197] `OperatorDeleteWrapper`, [UID:000373] `LObjectScalarDeletingDestructor`, [UID:0000WL] `ThreadDefaultNoOpVirtual`, and [UID:0000WM] `LObjectDefaultNoOpVirtual`.
- Prior B003 executed report `Agent-B003/research/executed/0002J5-0002J9-0002JA-0002JC-0002JD-0002JF-0002JG-popup-menu-controls-source-quality.md`.
- Current `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `auto-generated/by-memory-tool-report.md`, and generated `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`.

Tooling and validation/state checks run:

- IDA MCP availability check against `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`; no live IDA DB edits or live IDA calls were possible in this pass.
- Raw PE evidence was gathered from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` using a local PE parser and Capstone 5.0.7 disassembly.
- `tools/int_convert.py` verified `0x3e = 62`, `0x18 = 24`, `0x0c = 12`, `0x02 = 2`, `0x41 = 65`, and `0x118 = 280`.
- `rg` checked current coverage/stats/generated rows for `0002JF`, `0x005172e0`, and `MenuItemScalarDeletingDestructor`.
- Generated output check shows `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` now has emitted source-authored menu methods from the prior pass, but no destructor-wrapper body for [UID:0002JF]. That is expected and should remain expected after this report.

## IDA MCP / Raw Evidence Facts

Live IDA MCP was unavailable, so this pass uses existing IDA-backed pages plus fresh raw PE evidence. The existing target/support pages already record prior IDA `lookup_funcs`, `callers`, `callees`, and `xrefs_to` evidence. Fresh raw checks corroborate and refine that evidence.

Raw PE section context:

- Image base: `0x00400000`.
- `.text`: `0x00401000-0x0060c600`.
- `.rdata`: `0x0060d000-0x0066c200`.
- [UID:0002JF] lies in `.text` at raw file offset `0x1166e0`.

Boundary and padding facts:

- Preceding padding `0x005172d4-0x005172e0` is twelve `0xcc` bytes, `0x0c` / 12 bytes (Verified with `int_convert.py`).
- Target body `0x005172e0-0x0051731e` is `0x3e` / 62 bytes (Verified with `int_convert.py`).
- Following padding `0x0051731e-0x00517320` is two `0xcc` bytes, `0x02` / 2 bytes (Verified with `int_convert.py`).

Target bytes:

```text
55 8b ec 56 8b f1 c7 06 98 eb 61 00 e8 9f d7 fd ff 8b 45 08 a8 01 74 1f a8 04 75 10 56 e8 be d7 fd ff 83 c4 04 8b c6 5e 5d c2 04 00 6a 18 56 e8 8c 43 f0 ff 83 c4 08 8b c6 5e 5d c2 04 00
```

Fresh Capstone disassembly:

```asm
005172e0  push   ebp
005172e1  mov    ebp, esp
005172e3  push   esi
005172e4  mov    esi, ecx
005172e6  mov    dword ptr [esi], 0x0061eb98
005172ec  call   0x004f4a90
005172f1  mov    eax, dword ptr [ebp+8]
005172f4  test   al, 1
005172f6  je     0x00517317
005172f8  test   al, 4
005172fa  jne    0x0051730c
005172fc  push   esi
005172fd  call   0x004f4ac0
00517302  add    esp, 4
00517305  mov    eax, esi
00517307  pop    esi
00517308  pop    ebp
00517309  ret    4
0051730c  push   0x18
0051730e  push   esi
0051730f  call   0x0041b6a0
00517314  add    esp, 8
00517317  mov    eax, esi
00517319  pop    esi
0051731a  pop    ebp
0051731b  ret    4
```

Callee identities:

- `0x004f4a90`: [UID:000370] `LObjectDestructorBody`, the non-deleting base destructor body that restores the `LObject` vtable. This is source-authored base cleanup reached by derived destructors.
- `0x004f4ac0`: [UID:000197] `OperatorDeleteWrapper`, the MemoryMan-backed global `operator delete` wrapper. It routes deletion through `GetMemoryMan` and `FreeBufferMemory`.
- `0x0041b6a0`: raw one-byte `ret` helper, currently named by existing docs as `@_guard_check_icall_nop@4` in some contexts. Fresh raw bytes are `c3` followed by `0xcc` padding. This is not a `MenuItem` source helper and should be described as a compiler/no-op sized-delete path when explaining scalar-deleting destructor flags.

Precise deleting-flag behavior:

```cpp
// Descriptive pseudocode for the compiler wrapper only. Do not emit as target C++.
this->vptr = &MenuItem::vftable;
LObject::~LObject();

if ((flags & 1) != 0) {
    if ((flags & 4) != 0) {
        compiler_noop_sized_delete_path(this, 0x18);
    } else {
        operator delete(this);
    }
}

return this;
```

Important correction to preserve in docs: the flag-4 path is only reached after flag bit `1` is set, and the helper at `0x0041b6a0` is a no-op `ret`, not a second object-freeing helper. The normal free path is only `flags & 1` with `flags & 4` clear.

Pointer and caller-route checks:

- Whole-file little-endian dword search for target VA `0x005172e0` found exactly two hits:
  - raw `0x21d598` -> `.rdata:0x0061eb98`, the `MenuItem` vtable slot `+0x00`.
  - raw `0x21d5d0` -> `.rdata:0x0061ebd0`, the `SeparatorMenuItem` vtable slot `+0x00`.
- Search for target RVA `0x001172e0` found no hits.
- Search for target raw file offset `0x001166e0` found no hits.
- `.text` rel32 call/jump scan found no direct branch/call targets to `0x005172e0`.
- Search for `MenuItem` vtable VA `0x0061eb98` found expected immediate occurrences in the base constructor, `StringMenuItem` constructor, `SeparatorMenuItem` constructor, [UID:0002JF], and [UID:0002JG]. The [UID:0002JF] vtable reset immediate begins at `0x005172e8`, inside instruction `0x005172e6`.
- Search for `SeparatorMenuItem` vtable VA `0x0061ebd0` found the expected constructor install immediate at `0x00517207`.
- Search for `StringMenuItem` deleting destructor VA `0x00517400` found its vtable slot at `.rdata:0x0061ebb4`, confirming the sibling wrapper route.

Vtable route facts:

```text
MenuItem RTTI/vtable area:
0x0061eb94 -> 0x0064b604  RTTI/COL pointer
0x0061eb98 -> 0x005172e0  MenuItem scalar deleting destructor wrapper
0x0061eb9c -> 0x004f4b10  inherited runtime-class accessor
0x0061eba0 -> 0x0041b6c0  LObject default no-op virtual

SeparatorMenuItem RTTI/vtable area:
0x0061ebcc -> 0x0064b724  RTTI/COL pointer
0x0061ebd0 -> 0x005172e0  reused MenuItem scalar deleting destructor wrapper
0x0061ebd4 -> 0x004f4b10  inherited runtime-class accessor
0x0061ebd8 -> 0x0041b6c0  LObject default no-op virtual
0x0061ebe4 -> 0x00517250  separator draw slot
0x0061ebe8 -> 0x00517220  separator fixed-metrics slot
0x0061ebec -> 0x00517240  separator style-flags slot
```

Sibling comparison:

- [UID:0002JG] `StringMenuItemScalarDeletingDestructor` has the same wrapper pattern, but its flag-4 immediate is `0x118` / 280 bytes (Verified with `int_convert.py`) because `StringMenuItem` contains the inline `wchar_t m_text[0x80]` buffer at `+0x18`.
- [UID:0002JF] uses `0x18` / 24 bytes (Verified with `int_convert.py`), matching the recovered minimum `MenuItem` base layout through the state bytes at `+0x14/+0x15`.
- The separator vtable reuses [UID:0002JF] rather than pointing at a separate `SeparatorMenuItem` deleting-destructor wrapper. That supports "no explicit separator destructor source body" unless later source evidence contradicts it.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best defensible conclusion | Evidence checked | Rejected alternatives | Impact |
| --- | --- | --- | --- | --- |
| Exact boundary | Keep `0x005172e0-0x0051731e`. | Existing IDA `lookup_funcs` says start `0x005172e0`, size `0x3e`; raw PE confirms body bytes through `ret 4` at `0x0051731b` and two `0xcc` bytes after end. | Extending to include pre/post padding; merging with MenuPane scalar destructor at `0x00517320`; shortening before flag-4 return path. | Boundary is exact and supports score increase. |
| Padding | Prepad `0x005172d4-0x005172e0` and postpad `0x0051731e-0x00517320` are ignored alignment bytes. | Raw PE bytes are all `0xcc`; conversions verified with `int_convert.py`. | Treating padding as hidden code/table. | No split repair needed. |
| Callee role `0x004f4a90` | `LObject` non-deleting destructor body/base cleanup. | [UID:000370] documents exact `LObjectDestructorBody`; raw disassembly shows call immediately after resetting MenuItem vtable. | MenuItem-owned cleanup helper; unknown `sub_4F4A90`. | Use [UID:000370] and `LObject::~LObject()` semantics in docs. |
| Callee role `0x004f4ac0` | MemoryMan-backed global `operator delete` wrapper. | [UID:000197] documents `GetMemoryMan` -> `FreeBufferMemory`; raw disassembly calls it only in `flags & 1` and not `flags & 4` path. | Class-specific delete; ordinary free base; unknown `sub_4F4AC0`. | Confirms scalar-delete flag behavior and source-level `delete` expression route. |
| Callee role `0x0041b6a0` | Compiler no-op sized-delete/guard path, one-byte `ret`. | Raw bytes at `0x0041b6a0` are `c3` followed by `0xcc`; existing docs mention it as guard/no-op in destructor contexts; it is broadly reached by scalar-deleting destructors. | MenuItem source helper; second object-freeing helper; meaningful field cleanup function. | Mention exact no-op behavior; do not create source C++ for it in this target. |
| Deleting flags | `flags & 1` gates deletion; `flags & 4` diverts the deletion path to the no-op sized helper with object size `0x18`. | Raw instructions at `0x005172f4-0x00517314`; sibling [UID:0002JG] uses same pattern with size `0x118`; [UID:000373] `LObject` scalar wrapper has same broad pattern. | Generic "conditionally frees depending on flags" without flag order; independent flag-4 cleanup path; vector-delete free path. | Target docs should preserve exact branch order. |
| Direct callers | No ordinary direct code caller. | Existing IDA `callers(0x005172e0)` reports none; fresh `.text` rel32 scan found no direct branch/call target to `0x005172e0`. | Dead/unreachable helper; hidden direct call. | No-direct-caller status is expected for vtable destructor entry, not a dead-code blocker. |
| Pointer/table route | Only target VA pointer hits are MenuItem and SeparatorMenuItem vtable slots. | Raw dword search found exactly `.rdata:0x0061eb98` and `.rdata:0x0061ebd0`; no RVA/raw-offset hits. Existing [UID:0001Y4] records matching slots. | Hidden jump table; raw pointer route outside vtables; feature-local callback table. | Source reachability is vtable-owned and documented. |
| Owner | Direct owner remains [UID:00007V] `MenuItem`. | The wrapper resets the `MenuItem` vtable, object size is `0x18`, [UID:00007V] clears `86/88`, and `SeparatorMenuItem` vtable reuses this base wrapper. | Direct owner [UID:0000MN] `PopupMenuControls`; [UID:0000CY] `SeparatorMenuItem`; no owner. | Keep metadata `CANONICAL_OWNER:00007V`. |
| Emitter route | Keep emitter [UID:00007V] and source root [UID:0000MN] `PopupMenuControls`. | Generated route surfaces to `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`; class and file pages clear the gate; generated file already contains sibling source-authored methods. | Remove emitter because target C++ blank; route directly to file root; create new `MenuItem.cpp` now. | Keep metadata `EMITTER_UIDS:00007V`; no new source file. |
| Reconstructable policy | Keep `RECONSTRUCTABLE:TRUE`, but classify body as source-declared/generated-binary compiler wrapper. | Vtable slot must be regenerated by source class destructor semantics; by-structure allows documenting generated binary output from source declarations. | `RECONSTRUCTABLE:FALSE` ignored compiler glue; handwritten `ScalarDeletingDestructor` source method. | Raise score with no-code proof; do not hand-port wrapper. |
| Formal C++ | Keep [UID:0002JF] formal C++ blank. | Wrapper has `this`, `flags`, operator-delete, no-op guard path, and vtable reset machinery generated by MSVC; source should express an ordinary/default destructor. | Emit decompiler-shaped wrapper C++; leave blank only because "below 95/95"; reclassify as non-emitting. | C++ readiness resolved: target blank is correct for a target-specific reason. |
| Class-level source | Use ordinary/default `MenuItem` destructor semantics. | Wrapper calls only base `LObject` cleanup and conditional delete; no MenuItem fields require explicit cleanup. | `MenuItem::ScalarDeletingDestructor(unsigned int flags)`; explicit `SeparatorMenuItem::~SeparatorMenuItem()` body; custom delete method. | Add support doc guidance; final class/header can emit ordinary destructor declaration/body if needed. |
| Separator relationship | `SeparatorMenuItem` should inherit/reuse the base deleting wrapper. | Separator vtable slot `0x0061ebd0` points to [UID:0002JF]; constructor installs `SeparatorMenuItem` vtable but no separate destructor wrapper is referenced. | Separate `SeparatorMenuItem` scalar deleting destructor missing from docs; target should be owned by SeparatorMenuItem. | Supports base owner and prevents duplicate source destructor output. |
| Sibling [UID:0002JG] | Same compiler-wrapper policy, different object size. | Sibling raw bytes use same vtable reset, `LObject` cleanup, delete/no-op flag pattern, size `0x118`. | Treat [UID:0002JF] as special or dead because shared by separator. | The policy is consistent; a later sibling-only pass can raise [UID:0002JG] similarly if desired. |

Unresolved but non-blocking caveats:

- Original source may have used an explicit empty destructor declaration/body or relied on an implicit/default destructor. The binary proves ordinary destructor semantics but not exact source spelling.
- The one-byte `0x0041b6a0` no-op helper does not currently have its own exact by-memory page or coverage row. That broader stub-family documentation gap does not block [UID:0002JF]; the raw bytes and role are sufficient for this target.
- The target should stay below final-audit scores because no live IDA MCP was available in this session and exact original destructor declaration spelling is inferred.

## Existing Documentation Comparison And Stale/Open-Question List

Already correct or present at adequate detail:

- [UID:0002JF] already has the correct half-open range, current owner/emitter, reconstructable state, vtable-slot xrefs, no-direct-caller status, and blank formal C++ policy.
- [UID:00007V] already identifies [UID:0002JF] as a compiler-generated scalar deleting destructor wrapper and says source should declare an ordinary virtual destructor.
- [UID:0001Y4] already records both `MenuItem` and `SeparatorMenuItem` slot `+0x00` pointing to [UID:0002JF].
- [UID:0001V5] already establishes `MenuItem` base size/field evidence supporting the `0x18` object-size immediate.
- [UID:0000MN] already remains the best current source root for the popup-menu/menu-item family.

Stale or incomplete details to update:

- [UID:0002JF] should not remain `82/90` after this recheck. The old score implies the no-C++ policy is still a source-quality blocker, but the target-specific no-code proof resolves that blocker.
- The target behavior should record the exact flag order: `flags & 1` gates any delete work; if bit `4` is also set, the wrapper calls the no-op helper `0x0041b6a0` with `this` and size `0x18` rather than calling the operator-delete wrapper.
- The target should include full body bytes/disassembly or a concise raw PE evidence subsection so the score increase is auditable without session memory.
- Any old text saying C++ remains blank because the page is below a `95/95` gate should be replaced. Current reason: this exact range is compiler-generated wrapper output, not a source-authored method body.
- The prior B003 executed report says generated `PopupMenuControls.cpp` was length `0`; that is now stale. Current generated file length is `1582` bytes and contains first-draft source-authored menu methods, but no [UID:0002JF] body.

## Ranked Source / Owner Analysis

### 1. `MenuItem` class owner with `PopupMenuControls` source root

Accepted.

Evidence for:

- The wrapper resets the receiver vtable to `0x0061eb98`, the `MenuItem` vtable.
- The wrapper object size immediate is `0x18`, matching the recovered `MenuItem` base layout rather than `StringMenuItem`'s `0x118`.
- [UID:00007V] `MenuItem` clears the gate at `86/88`.
- [UID:0000MN] `PopupMenuControls` is the accepted source-file root for the menu-item family and surfaces to a generated source path.
- `SeparatorMenuItem` uses this same slot by inheritance/reuse, which is best explained by a base `MenuItem` destructor wrapper.

Evidence against:

- Exact original source spelling of the destructor is not proven.

Decision:

- Keep [UID:00007V] as direct semantic owner and emitter. This is the narrowest durable owner that satisfies by-structure rules.

### 2. Direct `PopupMenuControls` file owner

Rejected as direct owner, retained as source root.

Evidence for:

- The whole menu-item family is implemented under the current `PopupMenuControls` file page.

Evidence against:

- By-structure requires the narrowest true semantic owner. The wrapper is class-vtable owned, and [UID:00007V] now clears the gate.

Decision:

- Do not change `CANONICAL_OWNER` or `EMITTER_UIDS` from `00007V` to `0000MN`.

### 3. `SeparatorMenuItem` owner

Rejected.

Evidence for:

- `SeparatorMenuItem` vtable slot `+0x00` also points to `0x005172e0`.

Evidence against:

- The wrapper resets to the `MenuItem` vtable, not the separator vtable.
- The object size is the base `MenuItem` size.
- A separate separator destructor wrapper is not present; this is inherited/reused base destruction.

Decision:

- Document separator reuse as support evidence; do not route target ownership to [UID:0000CY].

### 4. Ignored/non-reconstructable compiler glue

Rejected for this page.

Evidence for:

- The exact instructions are compiler-generated scalar deleting destructor glue and should not be hand-authored.

Evidence against:

- The source class still needs destructor semantics that produce a vtable first slot and deleting wrapper in the rebuilt binary.
- Current project docs commonly keep vtable/destructor generated-binary artifacts reconstructable when source declarations are required to recreate them.
- [UID:0002JF] has a valid owner/emitter route; making it ignored would hide a real vtable/source-declaration requirement.

Decision:

- Keep `RECONSTRUCTABLE:TRUE`; use no-formal-C++ proof instead of ignored classification.

## Recommended Metadata And Score Changes

Target [UID:0002JF]:

```text
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:00007V
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007V
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Rationale:

- Completion rises because the target now has exact raw body bytes, precise flag behavior, no-direct-caller and vtable-only pointer evidence, callee identities, sibling comparison, owner/emitter validation, and a target-specific no-C++ proof.
- Confidence rises because the fresh raw PE evidence independently corroborates prior IDA-backed docs and closes the source-policy ambiguity that kept the target in low stats.
- Scores remain below final-audit because live IDA MCP was unavailable, the original destructor spelling remains inferred, and `0x0041b6a0` lacks its own exact helper page.

Support page metadata:

- [UID:00007V] `MenuItem`: no score change required, but add the class-level destructor source policy text below.
- [UID:0001Y4] `MenuItemVtables`: no score change required; optionally add the raw pointer-search confirmation that [UID:0002JF] target VA appears only in `MenuItem` and `SeparatorMenuItem` vtable slots.
- [UID:0001V5] `MenuItemLayouts`: no score change required; existing base-size/layout evidence supports the `0x18` immediate.
- [UID:0000MN] `PopupMenuControls`: no score or path change required.

Generated reports:

- `project-level/-auto-completion-stats.md` and `auto-generated/-ag-memory-coverage.md` are validator-owned/generated; do not hand-edit them. After target score update and validator autogen refresh, [UID:0002JF] should leave the refreshed low-completion/low-reconstructable queue while still showing no emitted C++ body by design.

## First-Draft C++ Recommendation / Target-Specific No-Code Proof

Do not populate [UID:0002JF] `RECONSTRUCTION_CPP CODE`.

Target-specific no-code proof:

- The exact body is an MSVC scalar deleting destructor wrapper. It takes a compiler destructor flag parameter, resets the vtable, calls base cleanup, conditionally calls the global delete wrapper, and includes a compiler no-op sized-delete path. That is ABI/compiler output, not hand-written NexusTK source.
- The only source-authored object behavior is ordinary destruction of `MenuItem`, which has no fields needing explicit cleanup beyond implicit base `LObject` destruction.
- `SeparatorMenuItem` uses the same vtable slot, which argues against emitting a separate handwritten `SeparatorMenuItem` destructor for this range.
- Emitting the wrapper body in C++ would hard-code compiler flags, vtable addresses, and allocation-helper calls in decompiler-shaped code. That would be less source-faithful than ordinary C++ destructor semantics.

Recommended class/support-level source shape, not to be pasted into [UID:0002JF]:

```cpp
class MenuItem : public LObject {
public:
    // The original source may have relied on an implicit/default destructor.
    // If a declaration is needed in the reconstructed class, keep it ordinary.
    virtual ~MenuItem();
};

MenuItem::~MenuItem()
{
}
```

Notes for supervisor application:

- If the final class reconstruction prefers an inline default destructor, `virtual ~MenuItem() {}` is also source-plausible. The binary does not prove whether the original destructor was explicit or compiler-implicit.
- Do not emit a `MenuItem::ScalarDeletingDestructor(unsigned int flags)` function in source.
- Do not add an explicit `SeparatorMenuItem::~SeparatorMenuItem()` unless later evidence proves the original source declared one. The current binary vtable reuses the base `MenuItem` deleting wrapper.
- Keep [UID:0002JF] formal C++ blank and record this no-code proof in the target page.

## Exact Supervisor Changes Required

Apply these changes to [UID:0002JF] `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md`:

1. Header updates:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave owner/emitter/reconstructable metadata and the formal C++ block unchanged.

2. Replace or update the status/reconstruction wording with this text:

```text
Rebuild handling: source-declared/generated-binary compiler wrapper. This exact range is the MSVC scalar deleting destructor wrapper generated for ordinary/default `MenuItem` destructor semantics. Keep the target formal C++ block blank; the source should express an ordinary `MenuItem` destructor on the class, and the compiler should regenerate this wrapper.
```

3. Add a raw-evidence subsection to the target page with the boundary, bytes, disassembly, pointer-route, and flag behavior recorded in this report. The most important wording to preserve is:

```text
B003 2026-06-18 raw PE recheck confirmed `0x005172e0-0x0051731e` as a `0x3e` / 62-byte wrapper (Verified with `int_convert.py`), with twelve `0xcc` bytes before it and two `0xcc` bytes after it. The body resets `[this]` to `0x0061eb98`, calls [UID:000370] `LObjectDestructorBody` at `0x004f4a90`, reads the deleting-destructor flags from `[ebp+8]`, calls [UID:000197] `OperatorDeleteWrapper` at `0x004f4ac0` only when `(flags & 1) != 0` and `(flags & 4) == 0`, and calls the one-byte no-op helper at `0x0041b6a0` with `this` and size `0x18` / 24 bytes (Verified with `int_convert.py`) when both flags bits are present. A raw dword scan found target VA `0x005172e0` only in the `MenuItem` and `SeparatorMenuItem` vtable slots, found no target RVA/raw-offset hits, and a `.text` rel32 scan found no direct calls or jumps to the target start.
```

4. Update the target score rationale with this text:

```text
Raised from `82/90` to `86/92` after B003 rechecked the wrapper policy and raw evidence. Completion now reflects exact bytes, padding, branch behavior, callee identities, vtable-only reachability, absence of direct callers, owner/emitter validation, and target-specific no-formal-C++ proof. Confidence remains below final-audit because live IDA MCP was unavailable for this session and the original source may have used either an explicit empty destructor or an implicit/default destructor, but this uncertainty no longer blocks 85/85 source-quality routing.
```

5. Add or update a target no-code proof section:

```text
Do not populate target formal C++. This range is compiler-generated deleting-destructor glue. The source-level representation is an ordinary/default `MenuItem` destructor; MSVC regenerates the deleting-wrapper flag checks, vtable reset, base cleanup call, no-op size path, and optional `operator delete` call. Handwriting those instructions in final source would be decompiler-shaped and less accurate than ordinary C++ destructor semantics.
```

Apply this support-doc insertion to [UID:00007V] `by-class/MenuItem.md`, preferably under the destructor method-map row or B003 source-quality incorporation section:

```text
Destructor source policy: [UID:0002JF] is the compiler-generated scalar deleting destructor wrapper for ordinary/default `MenuItem` destruction. The wrapper is reused by `SeparatorMenuItem` vtable slot `+0x00`; do not add a separate `SeparatorMenuItem` destructor unless later evidence proves an explicit source destructor. Reconstructed class-level source should use ordinary destructor semantics, for example an empty/default `MenuItem::~MenuItem()` if a definition is needed. The by-memory wrapper page should keep formal C++ blank because MSVC regenerates the flag checks, vtable reset, base `LObject` cleanup, and optional delete call.
```

Optional support-doc insertion for [UID:0001Y4] `MenuItemVtables.md`:

```text
2026-06-18 B003 raw PE recheck found the little-endian target pointer `0x005172e0` only at `.rdata:0x0061eb98` (`MenuItem` slot `+0x00`) and `.rdata:0x0061ebd0` (`SeparatorMenuItem` slot `+0x00`), with no target RVA/raw-offset hits and no `.text` rel32 callers. This strengthens the interpretation that [UID:0002JF] is vtable-owned deleting-destructor glue rather than an ordinary directly called helper.
```

No direct changes are required for [UID:0000MN] `PopupMenuControls`, [UID:0001V5] `MenuItemLayouts`, or generated `PopupMenuControls.cpp`.

## Coverage Report Replacement Text

Placement context: replace the existing [UID:0002JF] row inside the `0x00516290-0x00517441.MenuPaneAndItems` nested region of `source-3/project-documentation/by-memory/-coverage-report.md`, preserving address order between the `0x005172d4-0x005172e0` padding row and the `0x0051731e-0x00517320` padding row.

Current row to replace begins:

```text
        - [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) 0x005172e0-0x0051731e | compiler-generated destructor wrapper | MenuItemScalarDeletingDestructor : reconstructable : 82% : strong :
```

Replacement row:

```text
        - [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) 0x005172e0-0x0051731e | compiler-generated destructor wrapper | MenuItemScalarDeletingDestructor : reconstructable : 86% : very-strong : B003 2026-06-18 raw PE recheck confirms the exact `0x3e` / 62-byte wrapper (Verified with `int_convert.py`), twelve-byte prepad and two-byte postpad (Verified with `int_convert.py`), full body bytes, base vtable reset at `0x005172e6`, [UID:000370] `LObjectDestructorBody` call at `0x005172ec`, [UID:000197] `OperatorDeleteWrapper` call only for `flags & 1` with `flags & 4` clear, flag-4 path through the one-byte `0x0041b6a0` no-op helper with `0x18` / 24-byte object size (Verified with `int_convert.py`), target VA pointer hits only in the `MenuItem` and `SeparatorMenuItem` vtable slots, no target RVA/raw-offset hits, no `.text` rel32 direct callers, direct MenuItem class owner/emitter with PopupMenuControls source root, and explicit target-specific no-formal-C++ proof because source should express ordinary/default `MenuItem` destructor semantics and let MSVC regenerate the deleting-wrapper body.
```

## Validation Commands For Supervisor

After applying the target/support and coverage row changes, run:

> Executable block R001 was removed from this report and preserved verbatim in [0002JF-MenuItemScalarDeletingDestructor-source-quality-recheck-removed.md](0002JF-MenuItemScalarDeletingDestructor-source-quality-recheck-removed.md). The archived block is non-authoritative and must not be executed.

Expected validation outcome:

- Target page validates with updated `86/92` metadata and blank formal C++.
- Generated `PopupMenuControls.cpp` should remain without a [UID:0002JF] wrapper body.
- `auto-generated/-ag-memory-coverage.md` may still show [UID:0002JF] with code `no`; that is expected for this compiler-wrapper page and should not be treated as a missing-C++ failure once the no-code proof is documented.
- Refreshed `project-level/-auto-completion-stats.md` should no longer list [UID:0002JF] in the low-completion queue for this reason.

## Remaining Blockers

No blocker remains for raising [UID:0002JF] above the 85/85 source-quality gate.

Residual caveats that should cap the page below final-audit:

- Live IDA MCP was not reachable in this session, so the report relies on existing IDA-backed docs plus raw PE evidence.
- The binary does not prove whether original source explicitly declared/defined `MenuItem::~MenuItem()` or relied on implicit/default destructor generation. The class-level source recommendation should state this uncertainty rather than overclaim exact spelling.
- `0x0041b6a0` lacks its own exact by-memory coverage row/page even though raw bytes prove it is a one-byte no-op helper. This is a broader no-op/helper-family documentation issue, not a [UID:0002JF] score blocker.
- [UID:0002JG] likely deserves a later analogous recheck because it has the same compiler-wrapper policy and remains `84/90`; that is outside this single-target assignment and should not block [UID:0002JF].

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0002JF-MenuItemScalarDeletingDestructor-source-quality-recheck.md`
- Modified: none.
- No by-* docs, generated reports/source, IDA DB, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002JF-MenuItemScalarDeletingDestructor-source-quality-recheck.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002JF"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002JF-MenuItemScalarDeletingDestructor-source-quality-recheck-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002JF-MenuItemScalarDeletingDestructor-source-quality-recheck.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002JF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
