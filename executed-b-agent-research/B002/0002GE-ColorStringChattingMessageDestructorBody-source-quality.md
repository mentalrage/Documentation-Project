** TARGET-REPORT-UID:0002GE **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 source-quality report: [UID:0002GE] ColorStringChattingMessageDestructorBody

## Final recommendation

- Target: `source-3/project-documentation/by-memory/0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00002Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002Z`, blank formal C++.
- Recommended metadata: `COMPLETION:86`, `CONFIDENCE:90`, owner/emitter unchanged.
- Source route: keep [UID:00002Z] `ColorStringChattingMessage` as direct owner/emitter, through [UID:0000I5] `Chatting` and `auto-generated/NexusTK/social/Chatting.cpp`.
- Final source-facing name: `ColorStringChattingMessage::~ColorStringChattingMessage()`. The current by-memory filename/title may keep `DestructorBody` as a binary-range disambiguator because this exact range is the non-deleting destructor body, while [UID:0002GI] owns the scalar deleting destructor wrapper/compiler glue.
- C++ readiness: first-draft C++ is appropriate now. The old "below 95/95 source-emission gate" blocker is stale under the current combined-score/emitter rule.
- No split/merge/rename is recommended. The range is a single non-deleting destructor body with compiler EH scaffolding, not a mixed aggregate.

Recommended formal C++ block for the target:

```cpp
ColorStringChattingMessage::~ColorStringChattingMessage()
{
    if (m_text != NULL)
        m_text = static_cast<wchar_t *>(GetMemoryMan()->FreeBufferMemory(m_text));
}
```

If the accepted MemoryMan source layer models `FreeBufferMemory` as a free helper rather than a member-style call, the implementation may use the local established spelling while preserving the exact source semantics: release the owned `wchar_t *m_text` buffer at `+0x04` through `GetMemoryMan` / `FreeBufferMemory`, store the returned null back to `m_text`, and let the compiler emit the vtable restore plus `LObject` base destructor call.

## Scope and write guard

This was a report-only pass. I created/updated only this report:

`source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0002GE-ColorStringChattingMessageDestructorBody-source-quality.md`

I did not edit by-* docs, generated docs, generated source, IDA state, or `by-memory/-coverage-report.md`.

## Evidence checked

Instruction and structure references:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`, especially Rules 21, 24, 25, 26, 27, 30, and 31.
- `source-3/project-documentation/tools/leaser/Agents/Agent-B002/goal.md`, including the report-only and Implementation Callback Detail Contract rules.
- `.codex/AGENTS.md`.
- `source-3/project-documentation/by-structure.md`, especially the active `RECONSTRUCTION_CPP` gate and by-memory source-scope limits.
- `source-3/project-documentation/inference_research.md`, especially the guidance to separate direct facts from source/name inference and to check compiler artifacts.
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`, confirming the current `social/Chatting.cpp`, `util/MemoryMan.cpp`, and `util/LObject.cpp` routing.

Target and immediate support docs:

- [UID:0002GE] `by-memory/0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody.md`
- [UID:00002Z] `by-class/ColorStringChattingMessage.md`
- [UID:0000I5] `by-file/Chatting.md`
- [UID:0002GD] `by-memory/0x00483490-0x00483541.ColorStringChattingMessageConstructor.md`
- [UID:0002GF] `by-memory/0x004835b0-0x0048362b.ColorStringChattingMessageClone.md`
- [UID:0002GG] `by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md`
- [UID:0002GH] `by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md`
- [UID:0002GI] `by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md`
- [UID:0003AT] `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md`
- [UID:0001BC] `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
- [UID:0001BF] `by-memory/0x00516170-0x00516184.FreeBufferMemory.md`
- [UID:000370] `by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md`
- [UID:000195] `by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md`
- [UID:0000KV] `by-file/LObject.md`

Prior B-agent lead checked:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/0002F9-0002G8-0002GA-0002GE-0002GF-0002GG-ChattingPaintColorMessage-source-quality.md`

I treated the B011 report as a lead, not authority. Its target-specific recommendation for `0002GE` matches this pass: keep owner/emitter, raise to `86/90`, and add first-draft C++.

Independent binary checks:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- PE sections show `.text` is `0x00401000-0x0060c600`, so the destructor body and its `0x005fc1xx` cleanup/unwind references are inside executable/EH-bearing `.text` address space.
- Local IDA export listing slices and raw PE reference scans were used for the target, constructor, clone, scalar-deleting wrapper, `GetMemoryMan`, `FreeBufferMemory`, and `LObject` base destructor.

## IDA / binary facts

### Target boundary and padding

The destructor body range remains exact:

| Span | Bytes / role |
| --- | --- |
| `0x00483541-0x00483550` | fifteen `0xcc` bytes after the constructor body |
| `0x00483550-0x004835a9` | `0x59` byte non-deleting destructor body |
| `0x004835a9-0x004835b0` | seven `0xcc` bytes before the clone method |

Raw target bytes:

```text
55 8b ec 6a ff 68 ff c3 5f 00 64 a1 00 00 00 00
50 56 a1 24 2f 67 00 33 c5 50 8d 45 f4 64 a3 00
00 00 00 8b f1 8b 46 04 c7 06 6c 52 61 00 85 c0
74 10 50 e8 a8 2a 09 00 8b c8 e8 e1 2b 09 00 89
46 04 8b ce e8 f7 14 07 00 8b 4d f4 64 89 0d 00
00 00 00 59 5e 8b e5 5d c3
```

### Target disassembly

```asm
00483550  push    ebp
00483551  mov     ebp, esp
00483553  push    -1
00483555  push    0x5fc3ff
0048355a  mov     eax, dword ptr fs:[0]
00483560  push    eax
00483561  push    esi
00483562  mov     eax, dword ptr [0x672f24]
00483567  xor     eax, ebp
00483569  push    eax
0048356a  lea     eax, [ebp - 0xc]
0048356d  mov     dword ptr fs:[0], eax
00483573  mov     esi, ecx
00483575  mov     eax, dword ptr [esi + 4]
00483578  mov     dword ptr [esi], 0x61526c
0048357e  test    eax, eax
00483580  je      0x483592
00483582  push    eax
00483583  call    0x516030
00483588  mov     ecx, eax
0048358a  call    0x516170
0048358f  mov     dword ptr [esi + 4], eax
00483592  mov     ecx, esi
00483594  call    0x4f4a90
00483599  mov     ecx, dword ptr [ebp - 0xc]
0048359c  mov     dword ptr fs:[0], ecx
004835a3  pop     ecx
004835a4  pop     esi
004835a5  mov     esp, ebp
004835a7  pop     ebp
004835a8  ret
```

Confirmed operations:

- MSVC EH/security-cookie setup uses handler constant `0x005fc3ff`, cookie global `[0x00672f24]`, and `fs:[0]`.
- `ecx` is the receiver. The body saves it as `esi`.
- `[esi+0x04]` is loaded before the vtable write; this is the owned text pointer.
- `[esi] = 0x0061526c` restores the `ColorStringChattingMessage` vtable view for the derived destructor body.
- Non-null text path:
  - pushes the old text pointer as the `FreeBufferMemory` block argument,
  - calls `0x00516030` / [UID:0001BC] `GetMemoryMan`,
  - moves the returned singleton to `ecx`,
  - calls `0x00516170` / [UID:0001BF] `FreeBufferMemory`,
  - writes the helper result back to `[esi+0x04]`.
- `0x00516170` returns zero, so `[esi+0x04]` becomes null.
- The body calls `0x004f4a90` / [UID:000370] `LObjectDestructorBody`, which only restores the `LObject` vtable.
- The epilogue restores the SEH frame. No optional delete occurs in this non-deleting destructor body.

### Xref and reachability facts

Local PE scan facts:

- Rel32 references to `0x00483550`: `0x005fc139`, `0x005fc157`, `0x005fc1ab`, `0x005fc1b3`.
- These are cleanup/unwind references inside `.text` EH-support address space, not ordinary source callers.
- Raw PE scan found no absolute dword hits to `0x00483550` or `0x004835a9`; this supports the current classification that ordinary reachability is through compiler EH cleanup metadata rather than a normal source call or vtable slot.
- The absence of ordinary direct call sites is not a no-route proof. The body is still the source-derived non-deleting destructor body because the surrounding constructor/clone/draw/measure cluster, class vtable stores, EH references, and duplicated scalar-deleting cleanup all point to the same `ColorStringChattingMessage` destructor semantics.
- The `ColorStringChattingMessage` primary vtable slot at `0x0061526c` points to the scalar-deleting wrapper `0x00483e60`, not to the non-deleting body.
- Raw PE scan found the clone slot `0x004835b0` only as `.rdata:0x00615278` and the scalar wrapper `0x00483e60` as `.rdata:0x0061526c`, matching the documented vtable inventory.
- Absolute references to vtable address `0x0061526c` occur at `0x0047f19a`, `0x0047f2ea`, `0x0047f33d`, `0x004834ca`, `0x0048357a`, and `0x00483e91`. These cover chat construction paths, constructor store, destructor body store, and scalar wrapper store.
- Helper fanout is broad and utility-owned: the same PE scan found `612` rel32 calls to `0x00516030`, `210` rel32 calls to `0x00516170`, and `366` rel32 calls to `0x004f4a90`, so these helpers should be named and cross-referenced but not reassigned to Chatting.

### Callee set

| Callee | Current documented name | Role in target |
| --- | --- | --- |
| `0x00516030` | `GetMemoryMan` | Returns `g_pMemoryMan`; source-facing memory manager accessor. |
| `0x00516170` | `FreeBufferMemory` | Frees the supplied block, returns `0`; used here to release and clear `m_text`. |
| `0x004f4a90` | `LObjectDestructorBody` / `LObject::~LObject()` non-deleting body | Base destructor cleanup; restores `LObject` vtable. Compiler emits this from derived destructor inheritance. |

Negative callee evidence:

- No call to `0x004f4ac0` / operator delete occurs in the target body.
- No string class destructor, `StringBase` release, vector helper, or palette/color cleanup helper is called.
- No cleanup is performed for fields `+0x08`, `+0x0c`, `+0x10`, `+0x14`, or `+0x18`.

### Scalar-deleting wrapper relationship

The scalar-deleting wrapper at `0x00483e60-0x00483ef7` duplicates the same derived cleanup sequence and then handles deleting-destructor flags:

- Restores `ColorStringChattingMessage` vtable `0x0061526c`.
- Releases `[this+0x04]` through `GetMemoryMan` / `FreeBufferMemory` and stores the returned null.
- Calls `LObjectDestructorBody`.
- If `(flags & 1) != 0` and `(flags & 4) == 0`, calls `0x004f4ac0` operator-delete wrapper.
- If `(flags & 1) != 0` and `(flags & 4) != 0`, pushes `0x1c` and `this` before calling the `_guard_check_icall_nop` stub at `0x0041b6a0`; this is deleting-destructor/vector-delete compiler support shape, not a `ColorStringChattingMessage` source helper.
- Returns `this`.

The scalar wrapper belongs in [UID:0002GI] `ChattingUiDestructorGlueFamily` as compiler glue. It should not replace the source-authored destructor body on [UID:0002GE], and [UID:0002GE] should not emit optional delete or vector-delete flag logic.

## Field and helper-name resolution

### Text field

Best source-facing field name/type:

```cpp
wchar_t *m_text; // +0x04, owned heap UTF-16 buffer
```

Confidence: high.

Evidence:

- Constructor [UID:0002GD] scans incoming UTF-16 text, allocates `length * 2 + 2` bytes through `GetMemoryMan` / allocation helper `0x00516050`, copies through `0x00516220`, and stores the result at `+0x04`.
- Destructor [UID:0002GE] checks `+0x04` and frees only that pointer.
- Clone [UID:0002GF] passes the current `+0x04` pointer to the constructor, and the constructor duplicates it, making clone text ownership deep rather than shared.
- Measure [UID:0002GG] and draw [UID:0002GH] read the same pointer as UTF-16 text.
- Object size is `0x1c`, consistent with vptr plus pointer plus five color/custom fields.

Rejected alternatives:

- Inline text buffer: rejected because constructor writes a heap allocation pointer to `+0x04`, destructor frees it, and object size is only `0x1c`.
- Caller-owned text pointer: rejected because destructor releases the pointer and clone duplicates text through the constructor.
- `StringBase` / `SimpleUString` member: rejected because the constructor manually scans/copies and destructor directly calls MemoryMan free, not a string-object constructor/destructor.
- Generic `void *m_buffer`: weaker than `m_text` because measure/draw/constructor treat the field as UTF-16 text.

### Free helper pair

Best source-facing names:

```cpp
MemoryMan *GetMemoryMan();
void *MemoryMan::FreeBufferMemory(void *block);
```

or, if the local MemoryMan docs settle on free-function syntax:

```cpp
void *FreeBufferMemory(void *block);
```

The target page should name the concrete helper roles as [UID:0001BC] `GetMemoryMan` and [UID:0001BF] `FreeBufferMemory`, not leave `0x00516030` / `0x00516170` as raw unresolved addresses.

Evidence:

- [UID:0001BC] documents `0x00516030-0x00516036` as a six-byte accessor returning `g_pMemoryMan`.
- [UID:0001BF] documents `0x00516170-0x00516184` as `free(block); return 0`.
- The destructor's `mov ecx, eax` between these calls shows the source-level MemoryMan receiver/accessor relationship even though `FreeBufferMemory` does not currently use `ecx` internally.
- The return-value store to `[this+0x04]` matches the helper's null-return idiom.

Rejected alternatives:

- Unknown allocator helper names: rejected by current MemoryMan docs and direct helper bodies.
- `delete[] m_text`: rejected because the body calls MemoryMan's free helper, not the operator-delete wrapper or CRT delete-array path.
- `operator delete(m_text)`: rejected because `0x004f4ac0` is absent from the target body and appears only in scalar-deleting object-free wrappers.
- String release/refcount helper: rejected because no refcount decrement/string pool helper is called; this field is a direct MemoryMan allocation from the constructor.

### Base destructor relationship

Best source-facing interpretation:

- The source destructor should not explicitly call `LObject::~LObject()`.
- The binary call to `0x004f4a90` is compiler-emitted base destruction for the `LObject` base subobject after the derived destructor body.
- The target documentation should still record the call as binary evidence and cross-reference [UID:000370].

Rejected alternatives:

- Handwritten `LObject::~LObject()` call in source C++: rejected because C++ automatically invokes base destructors after derived destructor body; explicit source would be unidiomatic and could double-destroy in real source.
- Treating `0x004f4a90` as a ColorStringChattingMessage-owned helper: rejected because [UID:000370] proves it is the shared LObject non-deleting destructor body with hundreds of derived destructor refs.

## Relationship to sibling pages

### [UID:0002GD] Constructor

The constructor proves ownership and type of `+0x04`. It:

- calls `LObject::LObject()` at `0x004f4a80`,
- installs vtable `0x0061526c`,
- calls `GetMemoryMan`,
- allocates byte count including the UTF-16 terminator through allocation helper `0x00516050`,
- copies incoming UTF-16 text through `0x00516220`,
- stores the allocation at `+0x04`,
- writes foreground/background/custom fields at `+0x08`, `+0x0c`, `+0x10`, `+0x14`, and `+0x18`.

Destructor source should therefore release only `m_text` and leave scalar color fields alone.

### [UID:0002GF] Clone

The clone method allocates `0x1c` bytes and calls the constructor with current field values. Passing the current `m_text` pointer to the constructor is safe because the constructor duplicates the text. The clone is not a shallow owner-share.

Destructor source should therefore remain ordinary single-owner cleanup: every message instance frees its own duplicated `m_text`.

### [UID:0002GG] Measure and [UID:0002GH] Draw

Both pages use the same `+0x04` field as read-only UTF-16 text. They support the `m_text` field name but do not own or release the buffer.

### [UID:0002GI] Destructor glue

The scalar-deleting wrapper at `0x00483e60` is compiler-generated glue. It proves the class vtable and deleting-destructor path, but its optional delete and flag handling should remain in the glue page with no formal source C++. The ordinary destructor source belongs in [UID:0002GE].

## Heuristic / Inference Reanalysis And Validation

| Issue | Best direction | Evidence | Rejected alternatives / remaining cap |
| --- | --- | --- | --- |
| Destructor source shape | Source body releases `m_text` through MemoryMan helper and stores null. | Target disassembly, helper docs, constructor allocation path. | Blank C++ due old 95/95 gate rejected. |
| Field at `+0x04` | `wchar_t *m_text`, owned heap UTF-16 buffer. | Constructor alloc/copy, destructor free, clone deep-copy, draw/measure reads. | Inline buffer, caller-owned pointer, string object member rejected. |
| `0x00516030` | `GetMemoryMan()`. | Six-byte return of `g_pMemoryMan`; MemoryMan docs. | Config persistence or packet helper labels seen elsewhere are caller-context misnamings; here it is memory manager accessor. |
| `0x00516170` | `FreeBufferMemory`, returns null after freeing. | Helper body `free(block); return 0`; target stores EAX to `+0x04`. | `delete[]`, operator delete, string refcount release rejected. |
| `0x004f4a90` | `LObject::~LObject()` non-deleting body / base cleanup. | LObject docs and raw body vtable restore. | Do not source an explicit base call; compiler emits it. |
| No ordinary direct callers | Not a blocker. | EH refs plus scalar wrapper/vtable/constructor/class context prove destructor role. | No-owner/no-code rejected. |
| Vtable write `0x0061526c` | Compiler vtable restore during derived destructor. | Vtable data page and target/scalar wrapper stores. | Do not write vtable assignment in source C++. |
| Range split | Keep exact target range. | Padding before/after, one modeled body, no mixed callee/data range. | No child split needed. |
| Source placement | [UID:00002Z] under [UID:0000I5] `social/Chatting.cpp`. | Class/file docs, vtable cluster, constructor/clone/draw neighborhood. | MemoryMan owns callees only; LObject owns base destructor only; ChattingUiDestructorGlueFamily owns scalar wrapper only. |
| Score | `84/90 -> 86/90`. | Source blockers resolved and first-draft C++ ready. | Confidence stays 90 because exact original helper declaration spelling is still descriptive. |

## Negative evidence summary

- No call to `0x004f4ac0` appears in the target; object storage delete belongs to the scalar-deleting wrapper.
- No call to `StringBase`, `SimpleUString`, pool allocator, or refcounted string release helpers appears in the target.
- No write to color/custom fields occurs in the target.
- No direct source caller exists, but the non-deleting body has EH/unwind refs and a matching scalar-deleting wrapper. This is normal destructor-body evidence, not a reason to demote.
- No source/PDB filename evidence proves exact original helper spelling. This caps confidence but does not block descriptive source C++.

## Exact Target / Support Implementation Checklist

### Target edit

Path:

`source-3/project-documentation/by-memory/0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody.md`

Apply:

1. Change `COMPLETION:84` to `COMPLETION:86`.
2. Keep `CONFIDENCE:90`.
3. Keep `CANONICAL_OWNER:00002Z`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00002Z`.
4. Replace the stale "below 95/95 source-emission gate" statement with:
   - The current active source-entry gate is satisfied.
   - The destructor body is source-ready.
   - Remaining uncertainty is exact original MemoryMan helper declaration spelling, not behavior or source placement.
5. Add the resolved source-quality facts:
   - `+0x04` is `wchar_t *m_text`, an owned heap UTF-16 buffer.
   - `0x00516030` is `GetMemoryMan`.
   - `0x00516170` is `FreeBufferMemory`, which frees and returns null.
   - `0x004f4a90` is `LObjectDestructorBody` / base `LObject::~LObject()` non-deleting cleanup.
   - The vtable write to `0x0061526c`, EH handler constant `0x005fc3ff`, cookie `[0x00672f24]`, and base destructor call are compiler output around the source destructor body.
   - The cleanup/unwind refs are `0x005fc139`, `0x005fc157`, `0x005fc1ab`, and `0x005fc1b3`.
   - Boundary padding is `0x00483541-0x00483550` and `0x004835a9-0x004835b0`.
6. Add this formal C++:

```cpp
ColorStringChattingMessage::~ColorStringChattingMessage()
{
    if (m_text != NULL)
        m_text = static_cast<wchar_t *>(GetMemoryMan()->FreeBufferMemory(m_text));
}
```

If support declarations do not model a member-style `FreeBufferMemory`, use the established local helper spelling while preserving the `GetMemoryMan` / `FreeBufferMemory` evidence in prose.

### Support docs to update

1. `by-class/ColorStringChattingMessage.md`
   - Add or refresh the field table:
     - `+0x04 wchar_t *m_text`
     - `+0x08 m_foregroundColor`
     - `+0x0c m_backgroundColor`
     - `+0x10 m_useCustomColors` / custom flag byte
     - `+0x14 m_customForegroundRgb`
     - `+0x18 m_customBackgroundRgb`
   - Add that the destructor is first-draft C++ ready and releases only `m_text`.
   - Add that clone is deep for text because it calls the constructor, and that the destructor should not release color fields.

2. `by-file/Chatting.md`
   - Add a source-quality note that [UID:0002GE] is ready for emitted destructor source in `NexusTK/social/Chatting.cpp`.
   - Keep `ColorStringChattingMessage` under `Chatting.cpp`; do not create a new message-only source split from this evidence.

3. `by-memory/0x00483490-0x00483541.ColorStringChattingMessageConstructor.md`
   - Add a cross-note that the destructor pass resolves the text field as `m_text` and pairs the constructor allocation/copy with destructor `FreeBufferMemory`.

4. `by-memory/0x004835b0-0x0048362b.ColorStringChattingMessageClone.md`
   - Add that clone is not shallow text sharing because the constructor duplicates the passed `m_text`.
   - This supports the destructor's one-owner cleanup.

5. `by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md`
   - Add detail to the `0x00483e60-0x00483ef7` row that it duplicates the destructor text-release sequence and then handles scalar/vector delete flags.
   - Preserve `RECONSTRUCTABLE:FALSE` and blank C++ for the glue page.

6. `by-memory/0x00516030-0x00516036.GetMemoryMan.md` and `by-memory/0x00516170-0x00516184.FreeBufferMemory.md`
   - Optional support note only if the implementation callback includes them: `ColorStringChattingMessage::~ColorStringChattingMessage` is one field-clear caller; it uses `GetMemoryMan` then `FreeBufferMemory` and stores the null return.
   - Do not reroute those helpers to Chatting; MemoryMan remains their owner.

7. `by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md`
   - Optional support note only if touched: `ColorStringChattingMessage` is one derived destructor caller; the base call is compiler-emitted and should not be manually written into derived source C++.

## Exact coverage text

Do not edit `by-memory/-coverage-report.md` from the B-agent implementation pass.

Current supervisor-owned row to replace:

```text
        - [UID:0002GE][0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody](by-memory/0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody.md) 0x00483550-0x004835a9 | destructor body | ColorStringChattingMessageDestructorBody : reconstructable : 84% : strong : Live IDA verifies exact bounds, cleanup/unwind references, vtable ownership, owned wide-string release, base cleanup call, SEH context, and padding.
```

Supervisor-owned replacement row for the target:

```text
        - [UID:0002GE][0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody](by-memory/0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody.md) 0x00483550-0x004835a9 | destructor body | ColorStringChattingMessageDestructorBody : reconstructable : 86% : strong : B002 2026-06-19 source-quality pass resolves the source destructor as `ColorStringChattingMessage::~ColorStringChattingMessage()`, releasing owned `wchar_t *m_text` at `+0x04` through [UID:0001BC] `GetMemoryMan` and [UID:0001BF] `FreeBufferMemory`, storing the helper's null return, then relying on compiler-emitted vtable/base `LObject` cleanup; local IDA export and PE scan reconfirm the exact `0x59`-byte range, `0x00483541-0x00483550` and `0x004835a9-0x004835b0` padding, cleanup/unwind refs at `0x005fc139`, `0x005fc157`, `0x005fc1ab`, and `0x005fc1b3`, no absolute dword hits to the body start/end, vtable restore `0x0061526c`, callees `0x00516030`/`0x00516170`/`0x004f4a90`, constructor/clone ownership pairing, scalar wrapper separation, rejected StringBase/operator-delete alternatives, and first-draft C++ readiness.
```

Optional `by-class/-coverage-report.md` replacement row if class support detail is refreshed:

```text
- [UID:00002Z][ColorStringChattingMessage](by-class/ColorStringChattingMessage.md) : reconstructable : 86% : strong : Color chat message class with constructor/destructor/clone/line-count/draw child pages, draw tail tables, scalar deleting destructor glue context, and source-facing field model documented; destructor source-quality now resolves `m_text` ownership/freeing through MemoryMan while clone remains deep via constructor duplication.
```

Optional `by-file/-coverage-report.md` row: no score change required for [UID:0000I5] unless broader Chatting support text is refreshed.

## Scoped validator baseline result

Report-only validator baseline was run without `--apply`:

> Executable block R001 was removed from this report and preserved verbatim in [0002GE-ColorStringChattingMessageDestructorBody-source-quality-removed.md](0002GE-ColorStringChattingMessageDestructorBody-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`.
- Mode: `file`.
- Apply: `False`.
- Scanned markdown files: `1`.
- `ok: 1`.
- Direct success line: `ok 0002GE by-memory/0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody.md UID header exists`.
- Dry-run note: `dry run only; pass --apply to write changes`.
- Nonblocking generated-state chatter included project-wide `autogen_emitter_has_no_code` and `autogen_cpp_noop` lines; those are existing generated-output conditions and were not modified by this report-only pass.

## Validation commands for implementation callback

Expected commands after accepted implementation, from `source-3/project-documentation`:

> Executable block R002 was removed from this report and preserved verbatim in [0002GE-ColorStringChattingMessageDestructorBody-source-quality-removed.md](0002GE-ColorStringChattingMessageDestructorBody-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run the constructor/clone/glue validators only if those support docs are edited. Run the MemoryMan/LObject validators only if optional support notes are added there:

> Executable block R003 was removed from this report and preserved verbatim in [0002GE-ColorStringChattingMessageDestructorBody-source-quality-removed.md](0002GE-ColorStringChattingMessageDestructorBody-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After C++ insertion, run autogen refresh if the file validator does not refresh generated output:

> Executable block R004 was removed from this report and preserved verbatim in [0002GE-ColorStringChattingMessageDestructorBody-source-quality-removed.md](0002GE-ColorStringChattingMessageDestructorBody-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: validators pass after target/support docs are edited; generated `auto-generated/NexusTK/social/Chatting.cpp` should no longer contain an empty emitter marker for [UID:0002GE].

## IDA rename/type/comment recommendations

Suggested comments/types:

- At `0x00483550`: `ColorStringChattingMessage::~ColorStringChattingMessage() non-deleting body; releases owned m_text`.
- At `0x00483578`: `restore ColorStringChattingMessage vftable for derived destructor body`.
- At `0x00483583`: `GetMemoryMan()`.
- At `0x0048358a`: `MemoryMan::FreeBufferMemory(m_text); returns NULL for slot clear`.
- At `0x00483594`: `compiler-emitted LObject::~LObject() base cleanup`.
- At object offset `+0x04`: `wchar_t *m_text`.
- At `0x00483e60`: `ColorStringChattingMessage scalar deleting destructor wrapper; compiler glue, not handwritten source`.

Suggested source/decompiler type direction:

```cpp
class ColorStringChattingMessage : public LObject
{
    wchar_t *m_text;              // +0x04
    int m_foregroundColor;        // +0x08
    int m_backgroundColor;        // +0x0c
    bool m_useCustomColors;       // +0x10
    unsigned int m_customForegroundRgb; // +0x14
    unsigned int m_customBackgroundRgb; // +0x18
};
```

Keep exact original spellings marked inferred/descriptive; the offsets and ownership semantics are strong.

## Open questions closure

- Text pointer field name/type: resolved as owned `wchar_t *m_text` at `+0x04`.
- `0x00516030`: resolved as `GetMemoryMan`.
- `0x00516170`: resolved as `FreeBufferMemory`, free-and-return-null helper.
- `0x004f4a90`: resolved as `LObject` non-deleting destructor body/base cleanup.
- Constructor relationship: constructor allocates and copies text; destructor frees that allocation.
- Clone relationship: clone passes current text into constructor, which duplicates it; destructor owns each copy.
- Destructor glue relationship: scalar wrapper duplicates cleanup but remains compiler-generated no-C++ glue.
- Range/split: no split needed; padding is confirmed before/after.
- First-draft C++: appropriate and recommended.
- Remaining uncertainty: exact original MemoryMan helper declaration spelling, member-style versus free-function style. This caps confidence at `90` but does not block source C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002GE-ColorStringChattingMessageDestructorBody-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002GE"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002GE-ColorStringChattingMessageDestructorBody-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002GE-ColorStringChattingMessageDestructorBody-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002GE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
