<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B009\0004GX-NewUserMiscDialogPaneHandleCreateCharacterReply-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed operational material for 0004GX-NewUserMiscDialogPaneHandleCreateCharacterReply-source-quality.md

Source: [0004GX-NewUserMiscDialogPaneHandleCreateCharacterReply-source-quality.md](./0004GX-NewUserMiscDialogPaneHandleCreateCharacterReply-source-quality.md)

This companion is non-authoritative archival evidence. It must never be executed, adapted, or treated as a current request, procedure, mutation authority, or lifecycle instruction.

## Removed operational snapshot from 689A078F68930D527CAB5436781F101363DF5B413F33636674FF0D19323734F4

> Source: [0004GX-NewUserMiscDialogPaneHandleCreateCharacterReply-source-quality.md](./0004GX-NewUserMiscDialogPaneHandleCreateCharacterReply-source-quality.md)
> NON-AUTHORITATIVE ARCHIVE. Retained only for evidentiary no-loss review.
> NEVER EXECUTE, ADAPT, OR TREAT THE CONTENT BELOW AS A CURRENT REQUEST, PROCEDURE, MUTATION AUTHORITY, OR LIFECYCLE INSTRUCTION.

`````text
## IDA Rename / Type / Comment Recommendations

These accepted structured supervisor-owned Gate 2B rows are retained as the exact historical prestate/action/protection handoff. B009 reread the public MCP schemas read-only through transport session `bb99425b-5d7c-4f02-8b59-49e640691d22`: function and stack names use `rename`; function signatures use `set_type`; function-repeatable entry comments use `set_repeatable_comments`; `stack_frame`, `analyze_function`, `decompile`, `get_comments`, `entity_query`, function lookup, xrefs, and byte reads provide the required independent readback. The transport identity is dated evidence only and was not mutation authority. The supervisor later completed the handoff under a fresh canonical preflight and post-save readback.

| ID | Exact prestate | Proposed action | Evidence | Required readback and protection | Safety |
| --- | --- | --- | --- | --- | --- |
| I4GX-01 | `0x004fcb10` is `sub_4FCB10`, range `[0x004fcb10,0x004fccee)`, size `0x1de`, body SHA256 `D18BEDE3782D935B13EF0E82354363B3D2D111A9F028203590153AD5AB7E190E`, one inbound code xref `0x004fc5e1`; anchored `entity_query` currently returns zero exact function-name matches for `NewUserMiscDialogPane__HandleCreateCharacterReply` and one exact `sub_4FCB10` match at the target | Immediately rerun `entity_query {queries:{kind:"functions",regex:"^NewUserMiscDialogPane__HandleCreateCharacterReply$",count:10,fields:["addr","name","size"]},database:"<fresh-canonical-session>"}` and require total zero. Then run `rename {batch:{func:{addr:"0x004fcb10",name:"NewUserMiscDialogPane__HandleCreateCharacterReply"},stop_on_error:true,dry_run:true,allow_overwrite:false,pure:true},database:"<fresh-canonical-session>"}`, followed by the identical call with `dry_run:false` | Sole class caller and established source identity | Anchored collision query must still prove desired-name total zero immediately before dry-run; dry/live results must contain only the exact target/old/new rename and no directory/decompiler side-effect fields; read back exact new name, same range/size/body hash/xref, complete pre-type frame, all four blank entry/function comment channels, boundary bytes, and callee graph | Safe name-only action because `pure:true` is explicit and collision/prestate/protected readback is exact |
| I4GX-02 | Function type exactly `char __thiscall(Pane *this, int)`; register receiver is `Pane *this`; complete ten-row current frame is enumerated below | Run `set_type {edits:{addr:"0x004fcb10",kind:"function",signature:"bool __thiscall NewUserMiscDialogPane__HandleCreateCharacterReply(Pane *this, const unsigned char *packet)"},database:"<fresh-canonical-session>"}` | Always-true return, byte-indexed packet, one explicit four-byte packet argument, and absent complete target-class UDT | Read back exact bool thiscall prototype with `Pane *this` and one `const unsigned char *packet`; permit only the one argument-row delta listed below; protect every other row exactly; no new receiver row, argument, local, gap, merge, deletion, offset, width, or type delta is allowed | Safe only if complete post-type frame equals the literal matrix below |
| I4GX-03 | Frame/decompiler pairs are `Block +0x10/0x4`: frame `void *`, decompiler `MemoryMan *Block`; `WideCharStr +0x14/0x200`: frame/decompiler `WCHAR[256]`; `MultiByteStr +0x214/0x100`: frame/decompiler `CHAR[256]` | Run `rename {batch:{stack:[{func_addr:"0x004fcb10",old:"Block",new:"memoryMan"},{func_addr:"0x004fcb10",old:"WideCharStr",new:"wideText"},{func_addr:"0x004fcb10",old:"MultiByteStr",new:"narrowText"}],stop_on_error:true,dry_run:true,allow_overwrite:false,pure:false},database:"<fresh-canonical-session>"}`, followed by the identical call with `dry_run:false` | Exact retained receiver and buffer roles; public schema rejects pure mode for stack/local renames | `stack_frame` must show only the three names changed at identical offsets/widths/types; decompile must show `MemoryMan *memoryMan`, `WCHAR wideText[256]`, and `CHAR narrowText[256]`; all other post-I4GX-02 rows, prototype, bytes, xref, comments, and semantics remain exact | Deterministic stack rename with explicit non-pure mode; any frame/decompiler mismatch fails closed with no save |
| I4GX-04 | At `0x004fcb10`, `get_comments` returns address regular `""`, address repeatable `""`, function regular `""`, function repeatable `""`; all existing interior address comments listed by `analyze_function` are protected | Run entry-only `set_repeatable_comments {items:{addr:"0x004fcb10",comment:"Create-character reply: packet[1] is result, packet[2] is ANSI length, packet+3 is text; delete active screen dimmer, alert nonempty text, close only on result zero, and always return true."},database:"<fresh-canonical-session>"}` | Complete branch/call proof and public endpoint contract selecting `idc.set_func_cmt(...,True)` at a function entry | `get_comments` must return only function repeatable equal to the literal text; address regular/repeatable and function regular remain blank; every interior address comment, function name/type/frame, bytes, xref, boundaries, and callee graph remain exact | Safe isolated function-repeatable-channel action; `set_comments` is forbidden |
| I4GX-05 | Leading `0x004fcb0d-0x004fcb10`, body bytes, two-byte successor fence, sole xref, and callee graph match this report | No mutation; protected readback | Exact boundaries and behavior | Every protected byte, range, xref, and callee remains unchanged | Mandatory no-change guard |

Supervisor Gate 2B completion receipt: fresh post-save session `supervisor-uid0004GX-postsave-fresh-20260811` persisted `NewUserMiscDialogPane__HandleCreateCharacterReply`, exact signature `bool __thiscall NewUserMiscDialogPane__HandleCreateCharacterReply(Pane *this, const unsigned __int8 *packet)`, stack names/types `memoryMan` / `void *` and `MemoryMan *`, `wideText` / `WCHAR[256]`, and `narrowText` / `CHAR[256]`, plus the exact function-repeatable comment recorded above. Readback preserved sole xref `0x004fc5e1`, body SHA256 `D18BEDE3782D935B13EF0E82354363B3D2D111A9F028203590153AD5AB7E190E`, all protected frame/comment/boundary state, prebackup SHA256 `A6C49E6C...`, and canonical/postcopy SHA256 `35460C9A...`.

### I4GX-02 complete argument delta and protected frame matrix

| Row | Exact current prestate | Exact permitted poststate | Disposition |
| --- | --- | --- | --- |
| Register receiver | `Pane *this`; no stack-frame row | `Pane *this`; no stack-frame row | Protected unchanged |
| `Block` | `+0x10`, width `0x4`, frame type `void *` | `+0x10`, width `0x4`, frame type `void *` | Protected unchanged during I4GX-02 |
| `WideCharStr` | `+0x14`, width `0x200`, frame type `WCHAR[256]` | `+0x14`, width `0x200`, frame type `WCHAR[256]` | Protected unchanged during I4GX-02 |
| `MultiByteStr` | `+0x214`, width `0x100`, frame type `CHAR[256]` | `+0x214`, width `0x100`, frame type `CHAR[256]` | Protected unchanged during I4GX-02 |
| `var_10` | `+0x314`, width `0x4`, type `_DWORD` | `+0x314`, width `0x4`, type `_DWORD` | Protected unchanged |
| `var_C` | `+0x318`, width `0x4`, type `_DWORD` | `+0x318`, width `0x4`, type `_DWORD` | Protected unchanged |
| `var_4` | `+0x320`, width `0x4`, type `_DWORD` | `+0x320`, width `0x4`, type `_DWORD` | Protected unchanged |
| `__saved_registers` | `+0x324`, width `0x4`, type `_DWORD` | `+0x324`, width `0x4`, type `_DWORD` | Protected unchanged |
| `__return_address` | `+0x328`, width `0x4`, type `_UNKNOWN *` | `+0x328`, width `0x4`, type `_UNKNOWN *` | Protected unchanged |
| Explicit argument | `arg_0`, `+0x32c`, width `0x4`, type `_DWORD` / prototype `int` / decompiler name `a2` | `packet`, `+0x32c`, width `0x4`, type `const unsigned char *` | Only permitted frame-row delta |
| EH pseudo-argument | `arg_4`, `+0x330`, width `0x4`, type `_DWORD` | `arg_4`, `+0x330`, width `0x4`, type `_DWORD` | Protected unchanged; not a source parameter |

The post-I4GX-02 frame must contain exactly these ten physical rows in this order; the register receiver remains prototype-only. I4GX-03 may subsequently change only the first three physical row names as listed, never their types, offsets, widths, or storage.

### I4GX operation order and independent readback

The supervisor completed the accepted order below; it remains here as historical transaction evidence:

1. Fresh canonical read-only preflight and anchored collision query.
2. I4GX-01 function-rename dry-run, exact dry-run result check, live pure rename, then full protected readback.
3. I4GX-02 `set_type`, then exact prototype plus complete frame-matrix readback.
4. I4GX-03 stack-rename dry-run, exact dry-run result check, live non-pure stack rename, then complete frame plus decompiler readback.
5. I4GX-04 entry-only function-repeatable comment, then four-channel and full protected readback.
6. I4GX-05 final no-change protection readback. No unlisted delta was accepted.

No global rename, new UDT, data aggregation, item retyping, function creation/deletion, or address-comment rewrite is recommended.

`````

