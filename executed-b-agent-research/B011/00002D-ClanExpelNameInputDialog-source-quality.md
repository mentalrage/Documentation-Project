** TARGET-REPORT-UID:00002D **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B011 B-agent source-quality report: [UID:00002D] ClanExpelNameInputDialog

Status: FINISHED

## Target and report paths

- Target: `source-3/project-documentation/by-class/ClanExpelNameInputDialog.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00002D-ClanExpelNameInputDialog-source-quality.md`
- Related children checked:
  - [UID:0002NV] `source-3/project-documentation/by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md`
  - [UID:0002NW] `source-3/project-documentation/by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md`

## Executive recommendation

[UID:00002D] should remain source-bearing, reconstructable, and owned/emitted by [UID:0000I8] `Clan.cpp`, but the source-bearing unit should be the class declaration plus the already source-ready submit virtual child, not the standalone raw constructor body.

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:0000I8
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000I8
```

Recommended class-level formal C++:

```cpp
class ClanExpelNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanExpelNameInputDialog(const unsigned char *packet);

    virtual int OnSubmitText(const wchar_t *text);

    [[CHILDREN]]
};
```

The constructor source shape is high-confidence:

```cpp
ClanExpelNameInputDialog::ClanExpelNameInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}
```

However, I do not recommend emitting that body from [UID:0002NV] yet. Fresh raw binary checks still show no direct VA/RVA/pointer/immediate/direct-branch route to `0x00489140`; the live construction sites inline the equivalent base-constructor call plus derived vtable stores. Keep [UID:0002NV] C++ blank with a positive retained-raw policy, and let [UID:00002D] emit the declaration while [UID:0002NW] emits `OnSubmitText`.

## Evidence checked

Workflow and repository guidance:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B011/goal.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`

Target/support docs:

- `by-class/ClanExpelNameInputDialog.md`
- `by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md`
- `by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md`
- `by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md`
- `by-class/ClanNameInputDialog.md`
- `by-file/Clan.md`
- `by-file/ClanDialogs.md`
- `by-type/by-struct/ClanInputDialogLayouts.md`
- `by-type/by-vtable/ClanDialogVtableFamily.md`
- `by-type/by-vtable/ClanModalDialogVtables.md`
- `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md`
- `by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md`
- sibling class docs for DepMoney, SummonName, AppearName, ChangeName, and related Clan name-input dialog variants
- packet/helper docs for `PacketBufferWriteUInt8`, `QueueAndSendPacket`, `g_packetSender`, `MemmoveWrapper`, and Clan name action packet helpers
- B-agent prior research for Clan submitters and `ClanNameInputDialog` core

Binary evidence:

- Direct raw PE/Capstone pass over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Live IDA MCP was attempted at `127.0.0.1:13337/mcp`; the endpoint was unavailable, so this report uses current IDA-backed docs plus direct raw binary inspection.

## Raw constructor recheck

Raw constructor-shaped body at `0x00489140-0x00489175`:

```asm
00489140 push ebp
00489141 mov ebp, esp
00489143 push ecx
00489144 push esi
00489145 push dword ptr [ebp+8]
00489148 mov esi, ecx
0048914a mov [ebp-4], esi
0048914d call 0x00488b40
00489152 mov [esi], 0x00615ad8
00489158 mov eax, esi
0048915a mov [esi+0xa0], 0x00615b3c
00489164 mov [esi+0xa4], 0x00615b6c
0048916e pop esi
0048916f mov esp, ebp
00489171 pop ebp
00489172 ret 4
```

Range and padding:

- `0x00489132-0x00489140`: 14 bytes of `cc` padding before the raw constructor start.
- `0x00489140-0x00489175`: constructor-shaped bytes.
- `0x00489175-0x00489180`: 11 bytes of `cc` padding before the submitter.
- `0x0048926e-0x00489270`: 2 bytes of `cc` padding after the submitter.

Fresh route checks:

- VA dword scan for `0x00489140`: zero hits.
- RVA dword scan for `0x00089140`: zero hits.
- Direct relative branch/call scan to `0x00489140`: zero hits.
- The same VA/RVA/direct-branch scan pattern remains zero for sibling raw constructor starts in this family, supporting a family-level retained-raw pattern rather than a missed single xref.
- Existing IDA-backed docs already record no modeled IDA function object and no IDA xrefs to the raw start.

The raw constructor is still useful evidence. It proves the derived constructor source shape and the three vtable stores, but it should not be promoted into a source-emitting method body until the project accepts an explicit "retained raw duplicate constructor" policy or a live route is found.

## Live construction route

The lack of a call to `0x00489140` is not proof that the class is dead. Two active construction sites inline the same source-level operation:

```asm
004851c6 call 0x00488b40
004851cb mov [esi], 0x00615ad8
004851d1 mov [esi+0xa0], 0x00615b3c
004851db mov [esi+0xa4], 0x00615b6c
```

```asm
004881df call 0x00488b40
004881e4 mov [esi], 0x00615ad8
004881ea mov [esi+0xa0], 0x00615b3c
004881f4 mov [esi+0xa4], 0x00615b6c
```

These sites allocate/open the expel-name dialog by calling the shared `ClanNameInputDialog` constructor and then installing the `ClanExpelNameInputDialog` vtables. That supports a real source class and constructor declaration while explaining why the standalone raw body is not reached.

The inline allocation path also contains an allocation-size immediate `0x26c` before construction. I recommend documenting it as object-size evidence only, not as a new class-specific field claim; the shared layout docs already show no known expel-specific persistent members beyond the inherited `ClanNameInputDialog`/`DialogPane` storage.

## Vtable and layout resolution

Best-supported vtable family names and roles:

- Primary vtable: `0x00615ad8`
- Secondary vtable: `0x00615b3c`
- Tertiary vtable: `0x00615b6c`
- Submit virtual slot: `0x00615b34 -> 0x00489180`
- Store sites for this vtable group: `0x004851cb`, `0x004881e4`, and raw retained constructor bytes at `0x00489152`

The `0xa0` and `0xa4` stores match the existing `ClanInputDialogLayouts` secondary/tertiary subobject layout. I found no safe evidence for expel-specific fields; the derived class identity is expressed by vtable replacement plus the submit virtual override.

Destructor/deleting slots in the vtable group should not cause an explicit source destructor declaration for [UID:00002D]. They are compiler/inherited modal-dialog destructor/delete dispatch entries, not evidence of a handwritten `ClanExpelNameInputDialog::~ClanExpelNameInputDialog()`.

## Submitter and packet behavior

[UID:0002NW] is already correctly source-bearing as the virtual submit handler:

```cpp
int ClanExpelNameInputDialog::OnSubmitText(const wchar_t *text)
```

Fresh disassembly confirms the current child doc's packet behavior:

- Packet opcode byte: `0x4b`
- Clan-name-dialog subtype byte: `0x07`
- Expel action byte: `0x01`
- Text conversion: `WideCharToMultiByte(CP_ACP, ...)`
- Converted-name guard: `convertedLength < 0x100`
- Packet-size guard: `packetLength < 0x80`
- Payload copy: `memmove` wrapper at `0x00516220`
- Send route: `g_packetSender` at `0x0067a7ec`, call to `0x00574bb0` (`QueueAndSendPacket`)
- Packet-buffer helper: `0x00575380` is correctly modeled as `PacketBufferWriteUInt8`

The best source-facing action name is "expel-name submit" or "submit clan expel request". The virtual method name should remain `OnSubmitText`; naming it `SubmitName` loses the shared base virtual-slot meaning.

## Sibling comparison

Sibling Clan name-input dialogs use the same construction pattern:

- Raw constructor-shaped body with base `ClanNameInputDialog` call.
- Derived primary/secondary/tertiary vtable stores.
- No modeled direct route to the raw constructor start.
- Live open/dispatch code often inlines the equivalent construction.
- Submitter child owns the dialog-specific packet payload/action.

For [UID:00002D], this supports declaration-first class emission: the class exists, the submit virtual is source-ready, and the standalone raw constructor body remains retained raw evidence. The current sibling class pages still carry similar "class-level C++ blank" caveats; they should be handled by separate accepted passes rather than broad-editing them as part of this report.

## Source placement and ownership

Keep current ownership:

- `CANONICAL_OWNER:0000I8`
- `EMITTER_UIDS:0000I8`
- current output route: `auto-generated/NexusTK/social/Clan.cpp`

`ClanDialogs.cpp` remains a plausible future split candidate, but it is not strong enough to move this class. The current `Clan.md` route has stronger support, and generated `ClanDialogs.cpp` is currently empty. The class-level declaration and submitter child should therefore remain under `Clan.cpp` until a wider Clan dialog file split is implemented.

## Open questions and attempted resolution

1. Is `0x00489140` live code?

   Best answer: no direct live route is currently proven. I checked VA/RVA dword references and direct branches in the raw PE, and current IDA-backed docs record no function object/xrefs. This does not make the class no-code; live callers inline the equivalent construction at `0x004851c6` and `0x004881df`.

2. Should [UID:0002NV] emit a constructor body?

   Best answer: not yet. The source shape is high-confidence, but emitting the body from a no-route raw range would conflate retained compiler/raw evidence with a routed source method body. Keep the child formal C++ blank; emit the declaration at [UID:00002D].

3. What is the constructor parameter type?

   Best answer: `const unsigned char *packet`. The base constructor decodes the prompt from bytes at `packet[3]` and `packet + 4`, and the inline construction/open sites pass packet-like data through to `ClanNameInputDialog`.

4. Does the class have expel-specific fields?

   Best answer: no current evidence. Vtable stores at `+0`, `+0xa0`, and `+0xa4` identify the derived subobjects; inherited control-host state is at `+0x1fc`. No expel-specific persistent fields were found.

5. Should the class declare a destructor?

   Best answer: no. The vtable family contains destructor/deleting dispatch slots as part of the inherited modal-dialog class family, but no source-authored expel-specific destructor body is evidenced.

6. Are helper names stable enough?

   Best answer: yes for this class page. `PacketBufferWriteUInt8`, `QueueAndSendPacket`, `g_packetSender`, `WideCharToMultiByte`, and `memmove` are sufficiently supported by existing helper docs and child submitter evidence. Any future sender-interface typedef refinement does not block [UID:00002D].

## Rejected alternatives

- No-code class page: rejected. The live inline construction sites, vtable group, and virtual submitter slot prove a real source class even though the standalone raw constructor range is not reached.
- Emit raw constructor body from [UID:0002NV]: rejected for now. The body is source-shaped, but direct route evidence remains absent.
- Move owner to `ClanDialogs.cpp`: rejected for now. It is a reasonable future split, not the current best owner/emitter.
- Rename submitter as a one-off packet helper: rejected. The vtable slot and shared `ClanNameInputDialog` dispatch prove it is the derived virtual `OnSubmitText`.
- Add expel-specific data members: rejected. The evidence supports no persistent fields beyond inherited layout.

## Exact recommended target doc changes

In `by-class/ClanExpelNameInputDialog.md`:

1. Update metadata to `COMPLETION:86`, `CONFIDENCE:90`; keep owner/emitter/reconstructable unchanged.
2. Replace the stale "class-level C++ remains blank because raw constructor/class declaration not final" status with:

```text
Class declaration is now source-ready. The standalone raw constructor-shaped child [UID:0002NV] remains formal-C++ blank because no direct route to `0x00489140` is proven, but live construction sites inline the same base-constructor call plus derived vtable stores. [UID:0002NW] owns the expel-name submit virtual body.
```

3. Add the recommended formal C++ declaration:

```cpp
class ClanExpelNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanExpelNameInputDialog(const unsigned char *packet);

    virtual int OnSubmitText(const wchar_t *text);

    [[CHILDREN]]
};
```

4. Add/refresh evidence bullets:

```text
- Fresh B011 raw PE/Capstone recheck: `0x00489140-0x00489175` calls `ClanNameInputDialog` at `0x00488b40`, stores vtables `0x00615ad8`, `0x00615b3c`, and `0x00615b6c`, returns `ret 4`, and is bounded by `cc` padding.
- Fresh route scan found zero VA dword, RVA dword, or direct-branch references to `0x00489140`; current IDA-backed docs also record no function object/xrefs for the raw constructor start.
- Live construction sites at `0x004851c6` and `0x004881df` allocate/open the dialog by calling `ClanNameInputDialog` and then installing the same expel-name vtables, so the class declaration is source-ready even though the raw retained constructor body should stay C++ blank.
- Vtable slot `0x00615b34 -> 0x00489180` identifies [UID:0002NW] as the `OnSubmitText(const wchar_t *)` override.
- Submit behavior sends opcode `0x4b`, subtype `7`, action `1`, one-byte converted-name length, CP_ACP converted payload, and queues through `g_packetSender->QueueAndSendPacket`.
```

5. Add current caveats only as scoped caveats:

```text
Remaining caveats are class-family/source-placement caveats, not blockers for this class declaration: `ClanDialogs.cpp` remains a possible future split, sender-interface typedef spelling may refine `g_packetSender`, and the standalone raw constructor [UID:0002NV] has no direct route. These do not block [UID:00002D] from emitting a declaration or [UID:0002NW] from emitting the submit body.
```

## Exact recommended support doc changes

No support doc must change for correctness if the supervisor wants a minimal implementation. If touched for consistency, use these exact directions:

- [UID:0002NV] raw constructor: preserve `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:00002D]/[UID:0000I8] as currently modeled, and keep formal C++ blank. Add the high-confidence constructor source shape as evidence only:

```cpp
ClanExpelNameInputDialog::ClanExpelNameInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}
```

  Then explicitly state it is not emitted because raw PE and IDA-backed evidence still show no direct route to `0x00489140`; active live construction sites inline the same sequence.

- [UID:0002NW] submitter: no score or C++ change needed. If touched, align its source-facing name to `ClanExpelNameInputDialog::OnSubmitText(const wchar_t *)` and preserve opcode/subtype/action facts.

- `Clan.md`: update the `ClanExpelNameInputDialog` entry to say the class declaration is source-ready under `social/Clan.cpp`, [UID:0002NW] emits the submit body, and [UID:0002NV] remains retained raw/no-route constructor evidence.

- `ClanDialogs.md`: keep as future split candidate only; do not move [UID:00002D] ownership yet.

- `ClanInputDialogLayouts.md`: if touched, add that `ClanExpelNameInputDialog` adds no confirmed persistent fields beyond the inherited `ClanNameInputDialog` layout and derived vtable group.

- `ClanModalDialogVtables.md` or `ClanModalDialogVtableData.md`: if touched, add the slot detail `0x00615b34 -> 0x00489180` for the expel submit override, while preserving the vtable bases `0x00615ad8/0x00615b3c/0x00615b6c`.

## Coverage-report text

Do not edit `by-memory/-coverage-report.md`. No [UID:0002NV] or [UID:0002NW] by-memory coverage replacement is required; those rows already reflect the raw constructor/no-route and submitter/source-ready split.

Recommended exact replacement row for `by-class/-coverage-report.md`:

```text
- [UID:00002D][ClanExpelNameInputDialog](by-class/ClanExpelNameInputDialog.md) : reconstructable : 86% : very strong : B011 2026-06-19 source-quality pass resolves the class declaration/source route for the expel-name ClanNameInputDialog variant: raw PE/Capstone reconfirms the no-function/no-route constructor-shaped body at `0x00489140-0x00489175`, zero VA/RVA/direct-branch refs to `0x00489140`, live inline construction sites at `0x004851c6` and `0x004881df` that call `ClanNameInputDialog` then store vtables `0x00615ad8/0x00615b3c/0x00615b6c`, vtable slot `0x00615b34 -> 0x00489180`, subtype `7` action `1` expel-name packet behavior in child [UID:0002NW], current `social/Clan.cpp` owner/emitter route, and first-draft class declaration C++ with `[[CHILDREN]]`; raw constructor-body emission remains blank because standalone constructor reachability is unproven and active open sites inline equivalent construction.
```

## Validation commands after implementation

Run from `source-3/project-documentation` after any accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [00002D-ClanExpelNameInputDialog-source-quality-removed.md](00002D-ClanExpelNameInputDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation only changes the target class page and class coverage row, run only the target file, coverage file, and autogen validations.

## IDA rename/type/comment recommendations

- Keep `0x00489140` unpromoted unless the team adopts a retained-raw constructor promotion policy. If labels/comments are allowed without promotion, comment it as `ClanExpelNameInputDialog_ctor_raw_retained_no_direct_route`.
- Rename/comment `0x00489180` as `ClanExpelNameInputDialog::OnSubmitText(const wchar_t *)`; the older `SubmitName` wording is acceptable as a descriptive alias but should not replace the virtual method name.
- Comment vtable bases:
  - `0x00615ad8`: `ClanExpelNameInputDialog` primary vtable
  - `0x00615b3c`: `ClanExpelNameInputDialog` secondary vtable
  - `0x00615b6c`: `ClanExpelNameInputDialog` tertiary vtable
  - `0x00615b34`: submit virtual slot to `OnSubmitText`
- Type recommendation:

```cpp
class ClanExpelNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanExpelNameInputDialog(const unsigned char *packet);
    virtual int OnSubmitText(const wchar_t *text);
};
```

Confidence for these IDA recommendations: high for class/method/vtables; medium for raw constructor label wording because policy, not bytes, controls whether to promote it.

## Implementation readiness

Ready for supervisor implementation. The recommended implementation is scoped and low-risk:

- Update [UID:00002D] to `86/90`.
- Add class declaration C++ with `[[CHILDREN]]`.
- Replace stale no-C++ blocker with the routed declaration/no-route raw constructor split.
- Preserve [UID:0002NW] as the emitting submit body.
- Preserve [UID:0002NV] as retained raw constructor evidence with blank formal C++ unless supervisor explicitly chooses a broader retained-constructor emission policy.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00002D-ClanExpelNameInputDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00002D"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00002D-ClanExpelNameInputDialog-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00002D-ClanExpelNameInputDialog-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00002D"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
