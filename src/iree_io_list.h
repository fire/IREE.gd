#ifndef IREE_IO_LIST_H
#define IREE_IO_LIST_H

#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/classes/global_constants.hpp>

#include <iree/vm/api.h>
#include <iree/hal/api.h>

namespace godot {

class IREEIOList {
private:
    iree_vm_list_t* list;
public:
    enum ElementType {
        LIST,
        BUFFER_VIEW,
    };

    static Array to_array(const iree_vm_list_t* p_list);

    IREEIOList();
    IREEIOList(IREEIOList&& p_list);
    ~IREEIOList();

    bool is_init() const;
    Error init();
    void deinit();

    const iree_vm_list_t* ptr() const;
    iree_vm_list_t* ptrw();

    Array to_array() const;
    
    Error append(IREEIOList&& m_list); // move
    Error append(IREEBufferView&& m_buffer_view); // move
    Error append(iree_hal_buffer_view_t* m_buffer_view); // move
};

} // namespace godot

#endif//IREE_IO_LIST_H