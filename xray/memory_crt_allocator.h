////////////////////////////////////////////////////////////////////////////
//	Created 	: 03.10.2008
//	Author		: Dmitriy Iassenev
//	Copyright (C) GSC Game World - 2009
////////////////////////////////////////////////////////////////////////////

#ifndef MEMORY_DEFAULT_ALLOCATOR_H_INCLUDED
#define MEMORY_DEFAULT_ALLOCATOR_H_INCLUDED

#include <xray/memory_base_allocator.h>
#include <xray/memory_debug_parameters.h>

namespace xray {
namespace memory {

class XRAY_CORE_API crt_allocator : public base_allocator {
public:
					crt_allocator		( );
			pvoid	malloc_impl			( size_t size XRAY_CORE_DEBUG_PARAMETERS_DESCRIPTION_DECLARATION XRAY_CORE_DEBUG_PARAMETERS_DECLARATION );
			pvoid	realloc_impl		( pvoid pointer, size_t new_size XRAY_CORE_DEBUG_PARAMETERS_DESCRIPTION_DECLARATION XRAY_CORE_DEBUG_PARAMETERS_DECLARATION );
			void	free_impl			( pvoid pointer XRAY_CORE_DEBUG_PARAMETERS_DECLARATION );
	virtual	size_t	allocated_size		( ) const;
	void	user_current_thread_id() {} //stub!

private:
	typedef	base_allocator				super;

protected:
	virtual	pvoid	call_malloc			( size_t size XRAY_CORE_DEBUG_PARAMETERS_DESCRIPTION_DECLARATION XRAY_CORE_DEBUG_PARAMETERS_DECLARATION );
	virtual	pvoid	call_realloc		( pvoid pointer, size_t new_size XRAY_CORE_DEBUG_PARAMETERS_DESCRIPTION_DECLARATION XRAY_CORE_DEBUG_PARAMETERS_DECLARATION );
	virtual	void	call_free			( pvoid pointer XRAY_CORE_DEBUG_PARAMETERS_DECLARATION );

private:
	virtual	void	initialize_impl		( pvoid arena, u64 arena_size, pcstr arena_id );
	virtual	void	finalize_impl		( );
	virtual	size_t	total_size			( ) const;

private:
	typedef pvoid (*malloc_ptr_type)( size_t );
	typedef void (*free_ptr_type)( pvoid );
	typedef pvoid (*realloc_ptr_type)( pvoid, size_t );

private:
	malloc_ptr_type		m_malloc_ptr;
	free_ptr_type		m_free_ptr;
	realloc_ptr_type	m_realloc_ptr;
}; // class crt_allocator

typedef memory::crt_allocator				crt_allocator_type;
extern XRAY_CORE_API crt_allocator_type*	g_crt_allocator;

} // namespace memory
} // namespace xray

#endif // #ifndef MEMORY_DEFAULT_ALLOCATOR_H_INCLUDED