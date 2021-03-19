// Copyright 2008-2016 Conrad Sanderson (http://conradsanderson.id.au)
// Copyright 2008-2016 National ICT Australia (NICTA)
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ------------------------------------------------------------------------


//! \addtogroup fn_inv
//! @{



template<typename T1>
arma_warn_unused
arma_inline
typename enable_if2< is_supported_blas_type<typename T1::elem_type>::value, const Op<T1, op_inv> >::result
inv
  (
  const Base<typename T1::elem_type,T1>& X
  )
  {
  arma_extra_debug_sigprint();
  
  return Op<T1, op_inv>(X.get_ref());
  }



template<typename T1>
arma_warn_unused
arma_inline
typename enable_if2< is_supported_blas_type<typename T1::elem_type>::value, const Op<T1, op_inv_tr> >::result
inv
  (
  const Op<T1, op_trimat>& X
  )
  {
  arma_extra_debug_sigprint();
  
  // TODO: add handling of op_trimat to op_inv and remove this function
  
  return Op<T1, op_inv_tr>(X.m, X.aux_uword_a, 0);
  }



template<typename T1>
inline
typename enable_if2< is_supported_blas_type<typename T1::elem_type>::value, bool >::result
inv
  (
         Mat<typename T1::elem_type>&    out,
  const Base<typename T1::elem_type,T1>& X
  )
  {
  arma_extra_debug_sigprint();
  
  // TODO: refactor to remove "try catch"
  
  try
    {
    out = inv(X);
    }
  catch(std::runtime_error&)
    {
    return false;
    }
  
  return true;
  }



template<typename T1>
arma_warn_unused
arma_inline
typename enable_if2< is_supported_blas_type<typename T1::elem_type>::value, const Op<T1, op_inv_sympd> >::result
inv_sympd
  (
  const Base<typename T1::elem_type, T1>& X
  )
  {
  arma_extra_debug_sigprint();
  
  return Op<T1, op_inv_sympd>(X.get_ref());
  }



template<typename T1>
inline
typename enable_if2< is_supported_blas_type<typename T1::elem_type>::value, bool >::result
inv_sympd
  (
         Mat<typename T1::elem_type>&    out,
  const Base<typename T1::elem_type,T1>& X
  )
  {
  arma_extra_debug_sigprint();
  
  // TODO: refactor to remove "try catch"
  
  try
    {
    out = inv_sympd(X);
    }
  catch(std::runtime_error&)
    {
    return false;
    }
  
  return true;
  }



//! @}
